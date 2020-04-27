#!/usr/bin/env python3

import os
import glob
from pathlib import Path
from shutil import copyfile, copytree, rmtree
import subprocess
import zipfile
import glob
import mosspy

ZIPPED_FILES_FOLDER = 'zipped'
UNZIPPED_FILES_FOLDER = 'unzipped'
GRADING_OUTPUT_FOLDER = 'grading'
MASTER_FILES_FOLDER = 'master_files'
GRADING_WORKING_SUBFOLDER = os.path.join(GRADING_OUTPUT_FOLDER, 'working')
GRADING_COMPILATION_FAILED_SUBFOLDER = os.path.join(GRADING_OUTPUT_FOLDER, 'compilation_failed')
GRADING_CRASHED_SUBFOLDER = os.path.join(GRADING_OUTPUT_FOLDER, 'crashed')
MOSS_REPORT_FOLDER = 'moss_report'

simon_gauvin_id = 297240028
moss = mosspy.Moss(simon_gauvin_id, 'python')

POINTS_FOR_WARNINGS = '-1.5'
POINTS_FOR_NOT_COMPILING = '-4'
POINTS_FOR_CRASHING = '-2'
POINTS_FOR_LEAKS = '-2'

def unzip_files():
    # Only unzip if unzipped dir doesnt exists
    if os.path.isdir(UNZIPPED_FILES_FOLDER) == False:
        # unzip all files to unzipped folder
        print('Unzipping files')
        os.mkdir(UNZIPPED_FILES_FOLDER)
        # zipped_files = [f for f in listdir(zipped_files_dir) if isfile(join(zipped_files_dir, f))]
        for zipped_file in Path(ZIPPED_FILES_FOLDER).rglob('*.zip'):
            binome = str(zipped_file).split('.')[0].split('/')[1]
            zip_name = str(zipped_file).split('.')[0].split('/')[-1]
            zip_path = os.path.join(zipped_file)
            unzipped_folder = UNZIPPED_FILES_FOLDER + '/' + binome + ':_' + zip_name
            os.mkdir(unzipped_folder)
            with zipfile.ZipFile(zip_path, 'r') as zip_ref:
                zip_ref.extractall(unzipped_folder)

        subdirs = [x[0] for x in os.walk('.')]
        for dir in subdirs:
            if '__MACOSX' in dir.split('/')[-1]:
                rmtree(dir)

    else:
        print('Files already unzipped.')

    print('\n')


def grade_files():
    if os.path.isdir(GRADING_OUTPUT_FOLDER) == False:
        print('Correction des programmes des étudiants\n')
        os.mkdir(GRADING_OUTPUT_FOLDER)
        os.mkdir(GRADING_WORKING_SUBFOLDER)
        dirs = os.listdir(UNZIPPED_FILES_FOLDER)
        num = 0
        for folder_name in dirs:
            num += 1
            # Organize files and copy main.cpp and makefile
            path_to_dir = GRADING_WORKING_SUBFOLDER + '/' + folder_name
            os.mkdir(path_to_dir)
            os.mkdir(path_to_dir + '/src')
            os.mkdir(path_to_dir + '/include')

            with open(path_to_dir + '/points_to_rm.txt', 'w') as file:

                # for filepath glob.glob(unzipped_files_dir + '/' + folder_name + '/*.cpp'):

                for filepath in Path(UNZIPPED_FILES_FOLDER + '/' + folder_name).rglob('*.cpp'):
                    if filepath.is_file() == False:
                        continue
                    filename = str(filepath).split('/')[-1]
                    if filename in ['Makefile']:
                        continue
                    copyfile(filepath, path_to_dir + '/src/' + filename)

                for filepath in Path(UNZIPPED_FILES_FOLDER + '/' + folder_name).rglob('*.h'):
                    if filepath.is_file() == False:
                        continue
                    filename = str(filepath).split('/')[-1]
                    if filename == 'typesafe_enum.h':
                        continue
                    copyfile(filepath, path_to_dir + '/include/' + filename)

                copyfile(MASTER_FILES_FOLDER + '/Makefile', path_to_dir + '/Makefile')
                # copyfile(MASTER_FILES_FOLDER + '/main.cpp', path_to_dir + '/src/main.cpp')
                # copyfile(MASTER_FILES_FOLDER + '/typesafe_enum.h', path_to_dir + '/include/typesafe_enum.h')
                # TODO: Add files to overwrite here

                # Compile program
                proc = subprocess.Popen(['make', '-j', '-C', path_to_dir],
                                        stdout=subprocess.PIPE,
                                        stderr=subprocess.PIPE)

                stdout, stderr = proc.communicate()

                with open(path_to_dir + '/stdout.txt', 'w') as stdoutfile:
                    stdoutfile.write(stdout.decode('utf-8'))

                with open(path_to_dir + '/stderr.txt', 'w') as stderrfile:
                    stderrfile.write(stderr.decode('utf-8'))

                compiled = proc.returncode == 0

                output = str(num) + '/' + str(len(dirs)) + ' '

                if compiled == True:
                    warnings = False
                    if stderr:
                        warnings = True
                        file.write(POINTS_FOR_WARNINGS + ': Warnings\n')
                    output += folder_name + \
                        ' | Compiled: True | Warnings: ' + str(warnings)
                else:
                    print(output + folder_name + ' | Compiled: False')
                    file.write(POINTS_FOR_NOT_COMPILING + ': Ne compile pas\n')
                    file.close()
                    copytree(path_to_dir, GRADING_COMPILATION_FAILED_SUBFOLDER +
                             '/' + folder_name)
                    rmtree(path_to_dir)
                    continue

                executable_folder = path_to_dir + '/bin/linux/debug'

                # Copy text files TODO: Modify
                # copyfile(MASTER_FILES_FOLDER + '/restrictionsPays.txt', executable_folder + '/restrictionsPays.txt')
                # copyfile(MASTER_FILES_FOLDER + '/films.txt', executable_folder + '/films.txt')
                # copyfile(MASTER_FILES_FOLDER + '/auteurs.txt', executable_folder + '/auteurs.txt')

                # Run program

                # Check if program crash
                proc = subprocess.Popen(['make', 'run', '-C', path_to_dir],
                                        stdout=subprocess.PIPE,
                                        stderr=subprocess.PIPE)

                stdout, stderr = proc.communicate()
                crashed = proc.returncode != 0

                with open(path_to_dir + '/outputprog.txt', 'w') as outputprog:
                    outputprog.write(stdout.decode('utf-8'))

                if crashed == True:
                    print(output + ' | Crashed: True')
                    file.write(POINTS_FOR_CRASHING + ': Programme plante\n')
                    file.close()
                    copytree(path_to_dir, GRADING_CRASHED_SUBFOLDER + '/' + folder_name)
                    rmtree(path_to_dir)
                    continue

                output += ' | crashed: False'

                # Parse stdout for grade # TODO: Modify
                # programOutput = str(stdout)
                # startStr = 'TOTAL: '
                # endStr = '/8'
                # start = programOutput.find(startStr) + len(startStr) - 1
                # end = programOutput.find(endStr)
                # grade = programOutput[start : end]
                # grade = float(grade.strip())
                # output += ' | Tests :' + str(grade) + '/8'

                points_to_remove = 8.0  # - grade

                if points_to_remove != 0:
                    file.write('-' + str(points_to_remove) +
                               ': Certains tests échouent')

                # Check for memory leaks TODO: Install valgrind
                # proc = subprocess.Popen(['valgrind', '--tool=memcheck', '--leak-check=yes', '--error-exitcode=1',executable_folder + '/project'],
                #     stdout=subprocess.PIPE,
                #     stderr=subprocess.PIPE)

                # stdout, stderr = proc.communicate()

                # leaks_found = proc.returncode != 0
                # if leaks_found:
                #     file.write(POINTS_FOR_LEAKS + ': Fuite de mémoire')

                # output += ' | Leaks: ' + str(leaks_found)

                print(output)

    else:
        print('Correction déjà faite.\n')


def upload_moss():
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
    unzip_files()
    grade_files()
    # upload_moss()


if __name__ == '__main__':
    main()
