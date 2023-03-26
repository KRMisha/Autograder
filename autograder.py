#!/usr/bin/env python3

import glob
import os
import math
import re
import shutil
import subprocess
import sys
import zipfile
import config
import pickle
from pathlib import Path
from difflib import SequenceMatcher

def unzip_files(force_refresh):
    if config.UNZIPPED_FILES_FOLDER.is_dir():
        print('Unzipping already complete', end='')

        if force_refresh:
            print(' - Forcing refresh anyway')
            shutil.rmtree(config.UNZIPPED_FILES_FOLDER)
        else:
            print()
            return

    print('Unzipping files')

    # Create folder for unzipped files
    config.UNZIPPED_FILES_FOLDER.mkdir()

    # Initialize generator for all archives
    archives = (archive for archive in config.ZIPPED_FILES_FOLDER.glob('*') if archive.is_file())

    # Extract all archives
    for archive in archives:
        # Create destination folder
        section = archive.name.split("_")
        destination_folder = config.UNZIPPED_FILES_FOLDER.joinpath(section[3])
        os.makedirs(destination_folder, exist_ok=True)

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
                folder = destination_folder.as_posix().split('/')[-1]
                zipped_file.extract(file_info, os.path.join(destination_folder, (folder + '_' + file_info.filename.split('.')[0]).lower()))

def grade_programs(force_refresh):
    if config.GRADING_OUTPUT_FOLDER.is_dir():
        print('Grading already complete', end='')

        if force_refresh:
            print(' - Forcing refresh anyway')
            shutil.rmtree(config.GRADING_OUTPUT_FOLDER)
        else:
            print()
            return

    print('Grading student programs')

    # Create folder for student programs
    config.GRADING_OUTPUT_FOLDER.mkdir()
    config.GRADING_WORKING_SUBFOLDER.mkdir()
    config.GRADING_COMPILATION_FAILED_SUBFOLDER.mkdir()
    config.GRADING_CRASHED_SUBFOLDER.mkdir()

    unzipped_folders = list(config.UNZIPPED_FILES_FOLDER.iterdir())
    for index, current_unzipped_folder in enumerate(unzipped_folders, 1):
        for i, worker in enumerate(current_unzipped_folder.iterdir()):
            print(f'\t{index}/{len(unzipped_folders)}: {current_unzipped_folder.name}', end='')
            
            current_grading_folder = prepare_grading_folder(worker)

            if not compile_program(current_grading_folder):
                continue
        
            if not run_program(current_grading_folder):
                continue

            check_program_for_leaks(current_grading_folder)

            print()
            sys.stdout.flush()

def prepare_grading_folder(unzipped_folder):
    # Create folder structure
    grading_folder = config.GRADING_WORKING_SUBFOLDER / unzipped_folder.name
    grading_folder.mkdir()
    os.mkdir(grading_folder / 'src')
    os.mkdir(grading_folder / 'include')
    open(grading_folder / config.POINTS_TO_REMOVE_FILENAME, 'a').close()

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
    shutil.copy(config.MASTER_FILES_FOLDER / 'Makefile', grading_folder)
    for file in config.MASTER_FILES_FOLDER.glob('*.cpp'):
        shutil.copy(file, grading_folder / 'src')
    for file in config.MASTER_FILES_FOLDER.glob('*.h'):
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
        remove_points(current_grading_folder, score=0.0, reason='Compilation failed')
        current_grading_folder.replace(config.GRADING_COMPILATION_FAILED_SUBFOLDER / current_grading_folder.name)
        return False

    # Check for warnings
    warnings_emitted = len(process.stderr) > 0
    if warnings_emitted:
        pass
        # remove_points(current_grading_folder, config.PENALTY_FOR_WARNINGS, 'Warnings')
    print(f' | Warnings: {warnings_emitted}', end='')
    return True


def run_program(current_grading_folder):
    # Copy master text files to executable directory
    for file in config.MASTER_FILES_FOLDER.glob('*.txt'):
        shutil.copy(file, get_executable_path(current_grading_folder).parent)

    num_tests = 0
    num_tests_passed = 0

    print(f' | Test : ', end='')
    name = current_grading_folder.as_posix().split('/')[-1].lower()
    name = name.split('_')[-2] + '_' + name.split('_')[-1]
    try:
        for finput, foutput in zip(Path(os.path.join(config.TEST_INPUT_FOLDER, name)).iterdir(), Path(os.path.join(config.TEST_OUTPUT_FOLDER, name)).iterdir()):
            pass
            with open(finput, 'rb') as test_input:
                process = subprocess.run(['make', 'run'], stdin=test_input, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, cwd=current_grading_folder, timeout=5)
                with open(current_grading_folder / 'program_output.txt', 'wb') as finput:
                    finput.write(process.stdout)
                try:
                    output = process.stdout.decode('utf-8')
                except:
                    output = process.stdout.decode('cp949')
            output = output[output.find('\n') + 1:]
            with open(foutput, 'r') as foutput:
                expected = foutput.read()
            num_tests += 1
            if len(expected) == 0:
                num_tests_passed += 1
                continue
            if expected in output:
                num_tests_passed += 1
                continue
        remove_points(current_grading_folder, score=math.floor(num_tests_passed/num_tests), reason='Passed test ')
    except:
        remove_points(current_grading_folder, score=1.0, reason='No test input ')
        print('No test input', end='')

    print(f' {num_tests_passed}/{num_tests}', end='')
                

    # # Run program with Makefile and save output
    # process = subprocess.run(['make', 'run'], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, cwd=current_grading_folder)
    # # process.communicate(input=open(config.MASTER_FILES_FOLDER / 'input.txt', 'rb').read())
    # with open(current_grading_folder / 'program_output.txt', 'wb') as file:
    #     file.write(process.stdout)

    # # Check if program crashed
    # program_crashed = process.returncode != 0
    # print(f' | Crashed: {program_crashed}', end='')

    # if program_crashed:
    #     print()
    #     remove_points(current_grading_folder, config.PENALTY_FOR_CRASH, 'Programme crash')
    #     current_grading_folder.replace(config.GRADING_CRASHED_SUBFOLDER / current_grading_folder.name)
    #     return False

    # # Parse automated test results
    # try:
    #     output = process.stdout.decode('utf-8')
    # except:
    #     output = process.stdout.decode('cp949')

    # tests_result = float(match.group(1)) if match else '?'

    # if tests_result != '?':
    #     lost_test_points = - (config.POINTS_FOR_TESTS - tests_result)
    #     should_remove_points = lost_test_points < 0
    # else:
    #     lost_test_points = '-?'
    #     should_remove_points = True

    # if should_remove_points:
    #     remove_points(current_grading_folder, lost_test_points, f'Échec de certains tests ({tests_result}/{config.POINTS_FOR_TESTS})')
    # print(f' | Tests: {tests_result}/{config.POINTS_FOR_TESTS}', end='')
    return True


def check_program_for_leaks(current_grading_folder):
    # Parse executable path from Makefile
    executable_path = get_executable_path(current_grading_folder)

    num_tests = 0
    num_tests_passed = 0
    name = current_grading_folder.as_posix().split('/')[-1].lower()
    name = name.split('_')[-2] + '_' + name.split('_')[-1]

    try:
        for finput, foutput in zip(Path(os.path.join(config.TEST_INPUT_FOLDER, name)).iterdir(), Path(os.path.join(config.TEST_OUTPUT_FOLDER, name)).iterdir()):
            pass
            with open(finput, 'rb') as test_input:
                try:
                    process = subprocess.run(['valgrind', '--leak-check=yes', '--error-exitcode=1', './' + executable_path.name],
                                            stdin = test_input, capture_output=True, cwd=executable_path.parent, timeout=60)
                except subprocess.TimeoutExpired:
                    # Timeout when Valgrind takes too long (give up on detecting leaks)
                    print(f' | Leaks: Timed out', end='')
                    return
            
            with open(current_grading_folder / 'valgrind_stderr.txt', 'wb') as file:
                file.write(process.stderr)

            # Check for memory leaks
            leaks_found = process.returncode == 1
            if leaks_found:
                print(f' | Leaks: {leaks_found}', end='')
                break
        print(f' | Leaks: {leaks_found}', end='')
        if leaks_found:
            remove_points(current_grading_folder, config.PENALTY_FOR_LEAKS, 'Fuite de mémoire')
    except:
        print('| Leaks: No test input', end='')

    # Run valgrind against program and save output
    
    


def remove_points(current_grading_folder, score, reason):
    _Q = current_grading_folder._parts[-1]
    S_id = _Q.split('_')[0]
    lab_id = _Q.split('_')[1]
    question_id = _Q.split('_')[2]
    print(f' | {S_id} | {lab_id} | {question_id}, {score}, {reason}', end='')



def get_executable_path(current_grading_folder):
    # Parse executable folder from Makefile printvars target
    process = subprocess.run(['make', 'printvars'], capture_output=True, cwd=current_grading_folder)
    stdout = process.stdout.decode('utf-8')
    bin_dir_match = re.search(r'BIN_DIR: "(.*)"', stdout)
    exec_match = re.search(r'EXEC: "(.*)"', stdout)
    return current_grading_folder / bin_dir_match.group(1) / exec_match.group(1)


def main():
    if not config.ZIPPED_FILES_FOLDER.is_dir():
        sys.exit('Error: zipped files folder does not exist')

    if not config.MASTER_FILES_FOLDER.is_dir():
        sys.exit('Error: master files folder does not exist')

    args = sys.argv[1:]
    force_refresh = 'force' in args

    unzip_files(force_refresh)
    grade_programs(force_refresh)


if __name__ == '__main__':
    main()

# Made by Misha Krieger-Raynauld and Simon Gauvin
