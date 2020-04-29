#!/usr/bin/env python3

import glob
import os
import re
import shutil
import subprocess
import sys
import zipfile
import mosspy
from pathlib import Path

# Folder configuration
ZIPPED_FILES_FOLDER = Path('zipped') # Note: contents should match Moodle batch download format
UNZIPPED_FILES_FOLDER = Path('unzipped')
MASTER_FILES_FOLDER = Path('master_files')
GRADING_OUTPUT_FOLDER = Path('grading')
GRADING_WORKING_SUBFOLDER = GRADING_OUTPUT_FOLDER / 'working'
GRADING_COMPILATION_FAILED_SUBFOLDER = GRADING_OUTPUT_FOLDER / 'compilation_failed'
GRADING_CRASHED_SUBFOLDER = GRADING_OUTPUT_FOLDER / 'crashed'
MOSS_REPORT_FOLDER = Path('moss_report')

# Grading settings (graded on 20)
POINTS_TO_REMOVE_FILENAME = 'points_to_rm.txt'
PENALTY_FOR_WARNINGS = -1.5
PENALTY_FOR_COMPILATION_FAILURE = -3
PENALTY_FOR_CRASH = -2
PENALTY_FOR_LEAKS = -2
POINTS_FOR_TESTS = 6
TESTS_RESULT_REGEX = r'Total pour tous les tests: (.*)\/6'

# Moss configuration
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
    UNZIPPED_FILES_FOLDER.mkdir()

    # Initialize generator for all archives
    archives = (archive for archive in ZIPPED_FILES_FOLDER.glob('*/*') if archive.is_file())

    # Extract all archives
    for archive in archives:
        # Create destination folder
        destination_folder = UNZIPPED_FILES_FOLDER / archive.parent.name
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
        print(f'\t{index}/{len(unzipped_folders)}: {current_unzipped_folder.name}', end='')

        current_grading_folder = prepare_grading_folder(current_unzipped_folder)

        if not compile_program(current_grading_folder):
            continue

        if not run_program(current_grading_folder):
            continue

        check_program_for_leaks(current_grading_folder)

        print()


def prepare_grading_folder(unzipped_folder):
    # Create folder structure
    grading_folder = GRADING_WORKING_SUBFOLDER / unzipped_folder.name
    grading_folder.mkdir()
    os.mkdir(grading_folder / 'src')
    os.mkdir(grading_folder / 'include')
    open(grading_folder / POINTS_TO_REMOVE_FILENAME, 'a').close()

    # Copy student files
    for file in unzipped_folder.glob('*.cpp'):
        if not file.is_file():
            continue
        shutil.copy(file, grading_folder / 'src')
    for file in unzipped_folder.glob('*.h'):
        if not file.is_file():
            continue
        shutil.copy(file, grading_folder / 'include')

    # Copy master files (and potentially overwrite student files)
    shutil.copy(MASTER_FILES_FOLDER / 'Makefile', grading_folder)
    for file in MASTER_FILES_FOLDER.glob('*.cpp'):
        shutil.copy(file, grading_folder / 'src')
    for file in MASTER_FILES_FOLDER.glob('*.h'):
        shutil.copy(file, grading_folder / 'include')

    return grading_folder


def compile_program(current_grading_folder):
    # Compile with Makefile and save output
    process = subprocess.run(['make', '-j'], capture_output=True, cwd=current_grading_folder)
    with open(current_grading_folder / 'compilation_stdout.txt', 'wb') as file:
        file.write(process.stdout)
    with open(current_grading_folder / 'compilation_stderr.txt', 'wb') as file:
        file.write(process.stderr)

    # Check for successful compilation
    compilation_failed = process.returncode != 0
    print(f' | Compiled: {not compilation_failed}', end='')

    if compilation_failed:
        print()
        remove_points(current_grading_folder, PENALTY_FOR_COMPILATION_FAILURE, 'Ne compile pas')
        current_grading_folder.replace(GRADING_COMPILATION_FAILED_SUBFOLDER / current_grading_folder.name)
        return False

    # Check for warnings
    warnings_emitted = len(process.stderr) > 0
    if warnings_emitted:
        remove_points(current_grading_folder, PENALTY_FOR_WARNINGS, 'Warnings')
    print(f' | Warnings: {warnings_emitted}', end='')
    return True


def run_program(current_grading_folder):
    # Copy master text files
    for file in MASTER_FILES_FOLDER.glob('*.txt'):
        shutil.copy(file, get_executable_path(current_grading_folder))

    # Run program with Makefile and save output
    process = subprocess.run(['make', 'run'], stdout=subprocess.PIPE, stderr=subprocess.STDOUT, cwd=current_grading_folder)
    with open(current_grading_folder / 'program_output.txt', 'wb') as file:
        file.write(process.stdout)

    # Check if program crashed
    program_crashed = process.returncode != 0
    print(f' | Crashed: {program_crashed}', end='')

    if program_crashed:
        print()
        remove_points(current_grading_folder, PENALTY_FOR_CRASH, 'Programme crash')
        current_grading_folder.replace(GRADING_CRASHED_SUBFOLDER / current_grading_folder.name)
        return False

    # Parse automated test results
    match = re.search(TESTS_RESULT_REGEX, process.stdout.decode('utf-8'))
    tests_result = float(match.group(1)) if match else '?'

    if tests_result != '?':
        lost_test_points = - (POINTS_FOR_TESTS - tests_result)
        should_remove_points = lost_test_points < 0
    else:
        lost_test_points = '-?'
        should_remove_points = True

    if should_remove_points:
        remove_points(current_grading_folder, lost_test_points, f'Échec de certains tests ({tests_result}/{POINTS_FOR_TESTS})')
    print(f' | Tests: {tests_result}/{POINTS_FOR_TESTS}', end='')
    return True


def check_program_for_leaks(current_grading_folder):
    # Run valgrind against program and save output
    try:
        process = subprocess.run(['valgrind', '--leak-check=yes', '--error-exitcode=1', './project'],
                                 capture_output=True, cwd=get_executable_path(current_grading_folder), timeout=60)
    except subprocess.TimeoutExpired:
        # Timeout when Valgrind takes too long (give up on detecting leaks)
        print(f' | Leaks: Timed out', end='')
        return

    with open(current_grading_folder / 'valgrind_stderr.txt', 'wb') as file:
        file.write(process.stderr)

    # Check for memory leaks
    leaks_found = process.returncode == 1
    print(f' | Leaks: {leaks_found}', end='')

    if leaks_found:
        remove_points(current_grading_folder, PENALTY_FOR_LEAKS, 'Fuite de mémoire')


def remove_points(current_grading_folder, points_to_remove, reason):
    with open(current_grading_folder / POINTS_TO_REMOVE_FILENAME, 'a') as file:
        file.write(f'{points_to_remove}: {reason}\n')


def get_executable_path(current_grading_folder):
    # Parse executable folder from Makefile printvars target
    process = subprocess.run(['make', 'printvars'], capture_output=True, cwd=current_grading_folder)
    match = re.search(r'BIN_DIR: (.*)', process.stdout.decode('utf-8'))
    return current_grading_folder / match.group(1)


def generate_moss_report(force_refresh):
    if MOSS_REPORT_FOLDER.is_dir():
        print('Moss report already complete', end='')

        if force_refresh:
            print(' - Forcing refresh anyway')
            shutil.rmtree(MOSS_REPORT_FOLDER)
        else:
            print()
            return

    print('Generating Moss report')

    moss = mosspy.Moss(MOSS_USER_ID, 'python')

    # Create folder for Moss report
    MOSS_REPORT_FOLDER.mkdir()
    concatenated_files_folder = MOSS_REPORT_FOLDER / 'concatenated_files'
    concatenated_files_folder.mkdir()

    print('\tConcatenating source files')
    for unzipped_folder in UNZIPPED_FILES_FOLDER.iterdir():
        concatenated_file_path = concatenated_files_folder / (unzipped_folder.name + '.txt')

        # Concatenate source files into a single file
        with open(concatenated_file_path, 'w') as concatenated_file:
            patterns_to_concatenate = ['*.cpp', '*.h', '*.inl']

            source_file_paths_to_concatenate = []
            for pattern in patterns_to_concatenate:
                source_file_paths_to_concatenate.extend(unzipped_folder.glob(pattern))

            for source_file_path in source_file_paths_to_concatenate:
                with open(source_file_path, errors='replace') as source_file:
                    concatenated_file.write(source_file.read())

        # Only upload non-empty files
        if concatenated_file_path.stat().st_size > 0:
            moss.addFile(str(concatenated_file_path))

    # Upload files
    print('\tUploading files to Moss')
    report_url = moss.send()

    # Save generated report
    print('\tDownloading Moss report')
    moss.saveWebPage(report_url, MOSS_REPORT_FOLDER / 'report.html')
    mosspy.download_report(report_url, MOSS_REPORT_FOLDER / 'report', connections=8)


def main():
    args = sys.argv[1:]
    is_moss_report_mode = 'moss' in args
    force_refresh = 'force' in args

    if not is_moss_report_mode:
        unzip_files(force_refresh)
        grade_programs(force_refresh)
    else:
        generate_moss_report(force_refresh)


if __name__ == '__main__':
    main()

# Made by Simon Gauvin and Misha Krieger-Raynauld
