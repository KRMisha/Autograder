# Autograder

An automated grader for C++ projects!

## Features

- Unzip all submissions in one go
- Ensure certain files are not tampered with in each submission
- Compile, run, and check all programs for memory leaks all at once
- Apply points/penalties automatically for:
    - Compilation errors
    - Warnings
    - Crashing
    - Memory leaks
    - Unit test results
- Compare work for plagiarism using [Moss](https://theory.stanford.edu/~aiken/moss/)
- Output all grades with feedback in a CSV
- Email grades to every student with their individual feedback

Example:
![Autograder output](https://user-images.githubusercontent.com/30484238/102819793-318cb500-43a2-11eb-9631-10775fbd0a0b.png)

## Prerequisites

- GCC & Make
- [Python 3](https://www.python.org/downloads/)
- [Valgrind](https://valgrind.org/)

## Installation

1. Clone the repo and cd into it:

    ```sh
    git clone https://github.com/KRMisha/Autograder.git
    cd Autograder
    ```

3. Install the required packages
    - With a venv (recommended):

        ```sh
        python3 -m venv .venv
        source .venv/bin/activate # or .venv\Scripts\activate.bat on Windows
        pip install -r requirements.txt
        ```

    - Globally:

        ```sh
        pip install mosspy
        ```

## Setup

1. Download all the student submissions from your university's web portal (e.g. Moodle). Save them to the `zipped` directory.

    > The `zipped` directory should contain a list of folders each named with the submission's team name. Inside each of these team folders should be the respective team's turned in work as a zip archive. The name of the zip archive does not need to follow a specific convention.

    For example:
    ```
    zipped
    ├── S1_G4
    │   └── finalversion.zip
    ├── S2_G8
    │   └── 1234567_1234568_2.zip
    ├── S2_G9
    │   └── lab.zip
    └── ...
    ```

2. Fill in the tab-delimited `teams_info.csv` file with each student's information. For example:

    |LastName|FirstName    |ID     |Email                 |Team |
    |--------|-------------|-------|----------------------|-----|
    |Last1   |First1       |1234567|first1.last1@email.com|S2_G8|
    |Last2   |First2       |1234568|first2.last2@email.com|S2_G8|
    |Last3   |First3       |1234569|first3.last3@email.com|S2_G9|
    |Last4   |First4       |1234570|first4.last4@email.com|S2_G9|
    |...     |...          |...    |...                   |...  |

    Make sure to keep the header row with the named fields shown above.

    > The `Team` column's values should match the folder names inside the `zipped` directory. This is how the Autograder will match submissions with their author.

3. In the `master_files` directory, add any files you wish to have automatically copied to every team's submission before compiling (overwriting them if they already exist).

    This is useful for making sure each project has a Makefile, input text files, or that certain source files have not been tampered with by students (such as unit tests). Any files ending in a `.txt` file extension will automatically be copied into the built executable's directory.

    Tip: use the provided Makefile ([repo](https://github.com/KRMisha/Makefile)) to avoid needing to tweak `autograder.py`.

4. Edit the `config.py` file according to your needs:
    - Edit the "Grading settings" section to change the penalties associated with certain errors.
    - Change the `MOSS_USER_ID` variable to your Moss ID ([see the Moss instructions to learn how to obtain a Moss ID](https://theory.stanford.edu/~aiken/moss/))
    - Change `SMTP_SERVER` and `SMTP_PORT` to your email server's settings.
    - Change `SENDER_EMAIL` to the email address from which you will send the grades.
    - Change `EMAIL_SUBJECT` and `EMAIL_CONTENT` with the desired information.

## Usage

### Autograding

Unzip and autograde all submissions in a single step:

```sh
./autograder.py
```

This will first unzip all the zipped submissions into a new `unzipped` directory. Then, the following will be done for each submission:
- Copy the unzipped files and master files to a team folder inside the `grading` directory
- Compile the program
- Output any compilation errors and warnings to `make_stderr.txt`
- Run the program and save its output to `program_output.txt` (with both stdout and stderr)
- Parse the test results from the program output
- Output any memory leaks detected with Valgrind to `valgrind_stderr.txt`
- Create a `points_to_rm.txt` file. This file will contain the breakdown of points which have automatically been subtracted for compilation errors, warnings, crashes, leaks, or failed unit tests.

The team folders will be placed in either of the `compilation_failed`, `crashed` or `working` subdirectories of the `grading` folder depending on their state.

If an error occurs and you try to rerun `autograder.py`, the existing output folders will be detected and the script will halt to prevent accidentally overwriting everything. To force it to run again, use the following command:

```sh
./autograder.py force
```

### Manually grading style

Once each submission has been autograded and the `points_to_rm.txt` file has been created in each team's grading folder, you can now manually check each submission to grade aspects such as code style or good practices.

To do so, simply open each submission in the `grading` directory. To remove points with feedback, add a line to the team's `points_to_rm.txt` file with the following format, where the `#` represents any decimal number:

```
-#: Explanation for penalty
```

To grant bonus points, simply use a `+` sign rather than a `-` sign.

### Calculating grades

To calculate students' grades based on the feedback in each `points_to_rm.txt` file, use the following command:

```sh
./calculate_grades.py
```

This will create two CSV files in the `grades` directory. They both contain the same information but present it differently:
- `individual_grades.csv`: all the grades with feedback, one line per student
- `team_grades.csv`: all the grades with feedback, one line per team

### Checking for plagiarism

To check for plagiarism between teams by detecting excessive similarity, use the following command:

```sh
./check_plagiarism.py
```

This will compare all the files in the `unzipped` directory and output the report of similarity to `moss_report/report`. Simply open `moss_report/report/index.html` in your web browser to view the results.

To force the report to be regenerated if it has already been run, add the `force` option when invoking `check_plagiarism.py`.

### Sending grades by email

Finally, to send each student their grade and feedback as saved in `grading/individual_grades.csv`, use the following command:

```sh
./email_grades.py
```

After you provide your email login credentials at the prompt, an email will be sent to each student with their grade.

> Make sure to have set the email's desired content in `config.py` beforehand!

## Folder hierarchy overview

```
.
├── grades
│   └── individual_grades.csv               # Final grades for each student
│   └── team_grades.csv                     # Final grades grouped by team
├── grading
│   ├── compilation_failed                  # Programs which did not compile
│   │   ├── S1_G6
│   │   │   ├── <team files>
│   │   │   ├── compilation_stderr.txt      # Make stderr output (compilation errors and warnings)
│   │   │   ├── compilation_stdout.txt      # Make stdout output (which files compiled successfully)
│   │   │   └── points_to_rm.txt            # List of all removed points and feedback
│   │   └── ...
│   ├── crashed                             # Programs which compiled but crashed
│   │   ├── S1_G5
│   │   │   ├── <team files>
│   │   │   ├── compilation_stderr.txt
│   │   │   ├── compilation_stdout.txt
│   │   │   ├── points_to_rm.txt
│   │   │   └── program_output.txt          # The program output (both stdout and stderr)
│   │   └── ...
│   └── working                             # Programs which ran successfully
│       ├── S1_G1
│       │   ├── <team files>
│       │   ├── compilation_stderr.txt
│       │   ├── compilation_stdout.txt
│       │   ├── points_to_rm.txt
│       │   ├── program_output.txt
│       │   └── valgrind_stderr.txt         # The stderr output for valgrind
│       └── ...
├── master_files                            # The master files which are copied into each submission
│   └── <files>
├── moss_report
│   ├── concatenated_files
│   └── report                              # Plagiarism report generated by Moss
├── unzipped                                # Unzipped submissions with added master files
│   ├── S1_G1
│   └── ...
├── zipped                                  # Zipped submissions as downloaded
│   ├── S1_G1
│   └── ...
├── .gitignore
├── autograder.py
├── calculate_grades.py
├── check_plagiarism
├── config.py
├── email_grades.py
├── README.md
├── requirements.txt
└── teams_info.csv                          # CSV with each student's information
```

## License

[MIT](https://opensource.org/licenses/MIT)
