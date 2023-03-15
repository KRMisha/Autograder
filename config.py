from pathlib import Path

# Input files configuration
ZIPPED_FILES_FOLDER = Path('./zipped') # Contents should match Moodle batch download format
MASTER_FILES_FOLDER = Path('./master_files') # Include Makefile, *.cpp, *.h, and *.txt
TEAMS_INFO_PATH = Path('./teams_info.csv') # See calculate_grades.py for format

# Output files configuration
UNZIPPED_FILES_FOLDER = Path('./unzipped')
GRADING_OUTPUT_FOLDER = Path('./grading')
GRADING_WORKING_SUBFOLDER = GRADING_OUTPUT_FOLDER / 'working'
GRADING_COMPILATION_FAILED_SUBFOLDER = GRADING_OUTPUT_FOLDER / 'compilation_failed'
GRADING_CRASHED_SUBFOLDER = GRADING_OUTPUT_FOLDER / 'crashed'
MOSS_REPORT_FOLDER = Path('moss_report')
GRADES_OUTPUT_FOLDER = Path('./grades')
INDIVIDUAL_GRADES_PATH = GRADES_OUTPUT_FOLDER / 'individual_grades.csv'
TEAM_GRADES_PATH = GRADES_OUTPUT_FOLDER / 'team_grades.csv'

# Grading settings
POINTS_TO_REMOVE_FILENAME = 'points_to_rm.txt'
POINTS_TOTAL = 100
POINTS_FOR_TESTS = 100
TESTS_RESULT_REGEX = r'Total pour tous les tests: (.*)\/6'
PENALTY_FOR_WARNINGS = -20
PENALTY_FOR_COMPILATION_FAILURE = -100
PENALTY_FOR_CRASH = -100
PENALTY_FOR_LEAKS = -0

# Moss configuration
MOSS_USER_ID = 123456789

# Email report configuration
SMTP_SERVER = 'smtp.polymtl.ca'
SMTP_PORT = 587
SENDER_EMAIL = 'autograder@polymtl.ca'
EMAIL_SUBJECT = 'INF1010 - Correction TP#'
EMAIL_CONTENT = ('Bonjour {first_name},\n\n'
                 'Voici le détail de la correction pour le TP#. '
                 'Si vous avez des questions, vous pouvez répondre à ce courriel '
                 'et il me fera plaisir de vous expliquer.\n\n'
                 'Veuillez svp vérifier que les informations suivantes sont correctes:\n'
                 ' - Matricule: {id}\n'
                 ' - Binôme: {team}\n\n'
                 'Note: {grade}/{points_total}\n\n'
                 'Détail de la correction:\n{feedback}\n'
                 'Passez une bonne journée,\n\n'
                 'Autograder')

# Made by Misha Krieger-Raynauld and Simon Gauvin
