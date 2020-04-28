#!/usr/bin/env python3

import sys
import os
import glob
from pathlib import Path
import shutil
import subprocess
import zipfile
import mosspy

# Folder configuration
ZIPPED_FILES_FOLDER = Path('zipped') # Note: contents should match Moodle batch download format
UNZIPPED_FILES_FOLDER = Path('unzipped')
MASTER_FILES_FOLDER = Path('master_files')
GRADING_OUTPUT_FOLDER = Path('grading')
GRADING_WORKING_SUBFOLDER = GRADING_OUTPUT_FOLDER / 'working'
GRADING_COMPILATION_FAILED_SUBFOLDER = GRADING_OUTPUT_FOLDER / 'compilation_failed'
GRADING_CRASHED_SUBFOLDER = GRADING_OUTPUT_FOLDER / 'crashed'
MOSS_REPORT_FOLDER = Path('moss_report')

# Grading configuration
POINTS_TO_REMOVE_FILENAME = 'points_to_remove.txt'

# Grading settings (graded on 20)
PENALTY_FOR_WARNINGS = -1.5
PENALTY_FOR_COMPILATION_FAILURE = -3
PENALTY_FOR_CRASH = -2
PENALTY_FOR_LEAKS = -2

# MOSS configuration
MOSS_USER_ID = 297240028


def unzip_files(force_refresh):
    if UNZIPPED_FILES_FOLDER.is_dir():
        print('Unzipping already complete', end='')

        if force_refresh:
            print(' - Forcing refresh anyway')
            shutil.rmtree(UNZIPPED_FILES_FOLDER)
        else:
            print()
            return

    print('Unzipping files')

    # Create folder for unzipped files
    if UNZIPPED_FILES_FOLDER.is_dir():
        shutil.rmtree(UNZIPPED_FILES_FOLDER)
    UNZIPPED_FILES_FOLDER.mkdir()

    # Initialize generator for all archives
    archives = (archive for archive in ZIPPED_FILES_FOLDER.glob('*/*') if archive.is_file())

    # Extract all archives
    for archive in archives:
        # Create destination folder
        destination_folder_filename = archive.parent.name + '_-_' + archive.stem
        destination_folder = UNZIPPED_FILES_FOLDER / destination_folder_filename
        destination_folder.mkdir()

        # Output warning if archive format is unsupported
        if archive.suffix != '.zip':
            print(f'\tWarning: Skipping invalid archive format ({archive.suffix}) for folder \'{archive.parent.name}\'')
            continue

        # Unzip flattened file hierarchy
        with zipfile.ZipFile(archive, 'r') as zipped_file:
            for file_info in zipped_file.infolist():
                if file_info.is_dir():
                    continue
                
                is_file_macos_metadata = '__MACOSX' in file_info.filename
                if is_file_macos_metadata:
                    continue

                file_info.filename = os.path.basename(file_info.filename)
                zipped_file.extract(file_info, destination_folder)
    print()


def grade_programs(force_refresh):
    if GRADING_OUTPUT_FOLDER.is_dir():
        print('Grading already complete', end='')

        if force_refresh:
            print(' - Forcing refresh anyway')
            shutil.rmtree(GRADING_OUTPUT_FOLDER)
        else:
            print()
            return

    print('Grading student programs')
    
    # Create folder for student programs
    GRADING_OUTPUT_FOLDER.mkdir()
    GRADING_WORKING_SUBFOLDER.mkdir()
    GRADING_COMPILATION_FAILED_SUBFOLDER.mkdir()
    GRADING_CRASHED_SUBFOLDER.mkdir()

    unzipped_folders = list(UNZIPPED_FILES_FOLDER.iterdir())
    for index, current_unzipped_folder in enumerate(unzipped_folders, 1):
        print(f'\t{index}/{len(unzipped_folders)} {current_unzipped_folder.name}', end='')

        current_grading_folder = prepare_grading_folder(current_unzipped_folder)

        points_to_remove = []

        # Compile program
        process = subprocess.run(['make', '-j'], capture_output=True, cwd=current_grading_folder)

        with open(current_grading_folder / 'compilation_stdout.txt', 'wb') as stdout_file, \
             open(current_grading_folder / 'compilation_stderr.txt', 'wb') as stderr_file:
            stdout_file.write(process.stdout)
            stderr_file.write(process.stderr)

        program_compiled = process.returncode == 0
        if program_compiled == True:
            program_has_warnings = len(process.stderr) > 0
            if program_has_warnings:
                points_to_remove.append(f'{PENALTY_FOR_WARNINGS}: Warnings')
            print(f' | Compiled: True | Warnings: {program_has_warnings}', end='')
        else:
            print(' | Compiled: False')
            points_to_remove.append(f'{PENALTY_FOR_COMPILATION_FAILURE}: Ne compile pas')
            write_points_to_remove(current_grading_folder, points_to_remove)
            current_grading_folder.replace(GRADING_COMPILATION_FAILED_SUBFOLDER / current_grading_folder.name)
            continue

        # Run program

        # Copy text files
        executable_folder = current_grading_folder / 'bin/linux/debug'
        for file in MASTER_FILES_FOLDER.glob('*.txt'):
            shutil.copy(file, executable_folder)

        # Check if program crashes
        process = subprocess.run(['make', 'run'], stdout=subprocess.PIPE, stderr=subprocess.STDOUT, cwd=current_grading_folder)

        crashed = process.returncode != 0

        with open(current_grading_folder / 'program_output.txt', 'wb') as outputprog:
            outputprog.write(process.stdout)

        if crashed == True:
            print(' | Crashed: True')
            points_to_remove.append(f'{PENALTY_FOR_CRASH}: Programme plante\n')
            write_points_to_remove(current_grading_folder, points_to_remove)
            current_grading_folder.replace(GRADING_CRASHED_SUBFOLDER / current_grading_folder.name)
            continue

        print(' | Crashed: False')

        # Parse stdout for grade # TODO: Modify
        # programOutput = str(stdout)
        # startStr = 'TOTAL: '
        # endStr = '/8'
        # start = programOutput.find(startStr) + len(startStr) - 1
        # end = programOutput.find(endStr)
        # grade = programOutput[start : end]
        # grade = float(grade.strip())
        # output += ' | Tests :' + str(grade) + '/8'

        points_to_remove_for_tests = 8.0  # - grade

        if points_to_remove != 0:
            points_to_remove.append(f'-{points_to_remove_for_tests}: Certains tests échouent')

        # Check for memory leaks TODO: Install valgrind
        # proc = subprocess.Popen(['valgrind', '--leak-check=yes', '--error-exitcode=1', executable_folder + '/project'],
        #     stdout=subprocess.PIPE,
        #     stderr=subprocess.PIPE)

        # stdout, stderr = proc.communicate()

        # leaks_found = proc.returncode != 0
        # if leaks_found:
        #     file.write(PENALTY_FOR_LEAKS + ': Fuite de mémoire')

        # output += ' | Leaks: ' + str(leaks_found)

        write_points_to_remove(current_grading_folder, points_to_remove)



def prepare_grading_folder(current_unzipped_folder):
    # Create folder structure
    current_grading_folder = GRADING_WORKING_SUBFOLDER / current_unzipped_folder.name
    current_grading_folder.mkdir()
    os.mkdir(current_grading_folder / 'src')
    os.mkdir(current_grading_folder / 'include')

    # Copy student files
    for file in current_unzipped_folder.glob('*.cpp'):
        if not file.is_file():
            continue
        shutil.copy(file, current_grading_folder / 'src')
    for file in current_unzipped_folder.glob('*.h'):
        if not file.is_file():
            continue
        shutil.copy(file, current_grading_folder / 'include')

    # Copy master files (and potentially overwrite student files)
    shutil.copyfile(MASTER_FILES_FOLDER / 'Makefile', current_grading_folder / 'Makefile')
    for file in MASTER_FILES_FOLDER.glob('*.cpp'):
        shutil.copy(file, current_grading_folder / 'src')
    for file in MASTER_FILES_FOLDER.glob('*.h'):
        shutil.copy(file, current_grading_folder / 'include')
    
    return current_grading_folder


def compile_program():
    pass


def write_points_to_remove(current_grading_folder, points_to_remove):
    with open(current_grading_folder / 'points_to_rm.txt', 'w') as file:
        file.writelines(map(lambda x: x + '\n', points_to_remove))


def upload_moss():
    moss = mosspy.Moss(MOSS_USER_ID, 'python')

    # Plagiat:
    if not os.path.isdir(MOSS_REPORT_FOLDER):
        os.mkdir(MOSS_REPORT_FOLDER)
        concat_files_dir = MOSS_REPORT_FOLDER + '/concat_files'
        os.mkdir(concat_files_dir)
        print('Gathering files for MOSS')

        for folder_name in os.listdir(UNZIPPED_FILES_FOLDER):
            filename = concat_files_dir + '/' + folder_name + '.txt'
            with open(filename, 'w') as concat_file:
                print(filename)
                for filepath in Path(UNZIPPED_FILES_FOLDER + '/' + folder_name).rglob('*.cpp'):
                    if os.path.isfile(filepath) == False:
                        continue
                    with open(filepath, errors='replace') as infile:
                        for line in infile:
                            # line = line.decode('utf-8','ignore').encode('utf-8')
                            concat_file.write(line)
            if os.path.getsize(filename) != 0:  # if file is not 0 byte
                moss.addFile(filename)

        print('sending files to MOSS')
        url = moss.send()
        print('Plagiat url: ' + url)
        moss.saveWebPage(url, MOSS_REPORT_FOLDER + '/report.html')
        mosspy.download_report(url, MOSS_REPORT_FOLDER +
                               '/report/', connections=8)
    else:
        print('MOSS already done')


def main():
    force_refresh = 'force' in sys.argv

    unzip_files(force_refresh)
    grade_programs(force_refresh)
    # upload_moss()


if __name__ == '__main__':
    main()

# Made by Simon Gauvin and Misha Krieger-Raynauld 
