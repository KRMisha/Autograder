#!/usr/bin/env python3

import sys
import shutil
import mosspy
import config


def generate_moss_report(force_refresh):
    if config.MOSS_REPORT_FOLDER.is_dir():
        print('Moss report already complete', end='')

        if force_refresh:
            print(' - Forcing refresh anyway')
            shutil.rmtree(config.MOSS_REPORT_FOLDER)
        else:
            print()
            return

    print('Generating Moss report')

    moss = mosspy.Moss(config.MOSS_USER_ID, 'python')

    # Create folder for Moss report
    config.MOSS_REPORT_FOLDER.mkdir()
    concatenated_files_folder = config.MOSS_REPORT_FOLDER / 'concatenated_files'
    concatenated_files_folder.mkdir()

    print('\tConcatenating source files')
    for unzipped_folder in config.UNZIPPED_FILES_FOLDER.iterdir():
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
    mosspy.download_report(report_url, config.MOSS_REPORT_FOLDER / 'report', connections=8)


def main():
    if not config.UNZIPPED_FILES_FOLDER.is_dir():
        sys.exit('Error: unzipped files folder does not exist')

    args = sys.argv[1:]
    force_refresh = 'force' in args

    generate_moss_report(force_refresh)


if __name__ == '__main__':
    main()

# Made by Misha Krieger-Raynauld and Simon Gauvin
