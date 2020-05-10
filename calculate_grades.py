#!/usr/bin/env python3

import csv
import sys
import config


def load_teams_info():
    if not config.TEAMS_INFO_PATH.is_file():
        sys.exit('Error: teams info file does not exist')

    with open(config.TEAMS_INFO_PATH, newline='') as csv_file:
        reader = csv.DictReader(csv_file, delimiter='\t')
        return list(reader)


def main():
    if not config.GRADING_OUTPUT_FOLDER.is_dir():
        sys.exit('Error: grading folder does not exist')

    teams_info = load_teams_info()

    config.GRADES_OUTPUT_FOLDER.mkdir(exist_ok=True)

    points_to_remove_files = (file for file in config.GRADING_OUTPUT_FOLDER.rglob(config.POINTS_TO_REMOVE_FILENAME) if file.is_file())
    team_files = {file.parent.name: file for file in points_to_remove_files}

    # Calculate team grade totals
    team_fieldnames = ['Team', 'Grade', 'Feedback']
    team_grades = {}
    for team_name, filename in team_files.items():
        with open(filename) as file:
            grade = config.POINTS_TOTAL
            lines = file.readlines()
            for line in lines:
                points_to_remove = float(line.split(':')[0])
                grade += points_to_remove

            team_grades[team_name] = {
                team_fieldnames[0]: team_name,
                team_fieldnames[1]: grade,
                team_fieldnames[2]: ''.join(lines)
            }

    # Generate individual grades from team info
    individual_fieldnames = ['ID', 'FirstName', 'LastName', 'Email', 'Team', 'Grade', 'Feedback']
    individual_grades = []
    for team_info in teams_info:
        grade_info = team_info.copy()
        if team_info['Team'] in team_grades:
            grade_info.update(team_grades[team_info['Team']])
        else:
            grade_info['Grade'] = 0
            grade_info['Feedback'] = f'-{config.POINTS_TOTAL}: Aucun travail remis\n'
        individual_grades.append(grade_info)

    # Write team grades to csv
    with open(config.TEAM_GRADES_PATH, 'w', newline='') as csv_file:
        writer = csv.DictWriter(csv_file, fieldnames=team_fieldnames)
        writer.writeheader()
        for row in sorted(team_grades.values(), key=lambda x: x[team_fieldnames[0]]):
            writer.writerow(row)

    # Write individual grades to csv
    with open(config.INDIVIDUAL_GRADES_PATH, 'w', newline='') as csv_file:
        writer = csv.DictWriter(csv_file, fieldnames=individual_fieldnames)
        writer.writeheader()
        for row in sorted(individual_grades, key=lambda x: x[individual_fieldnames[0]]):
            writer.writerow(row)


if __name__ == '__main__':
    main()

# Made by Misha Krieger-Raynauld and Simon Gauvin
