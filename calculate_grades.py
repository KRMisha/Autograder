#!/usr/bin/env python3

import csv
from pathlib import Path

GRADING_FOLDER = Path('grading')
GRADES_OUTPUT_FOLDER = Path('grades')
TEAMS_INFO_FILENAME = 'teams_info.csv'
POINTS_TO_REMOVE_FILENAME = 'points_to_rm.txt'
POINTS_TOTAL = 20


def read_teams_info():
    with open(TEAMS_INFO_FILENAME, newline='') as csv_file:
        reader = csv.DictReader(csv_file, delimiter='\t')
        return list(reader)


def main():
    teams_info = read_teams_info()

    GRADES_OUTPUT_FOLDER.mkdir(exist_ok=True)

    points_to_remove_files = (file for file in GRADING_FOLDER.rglob(POINTS_TO_REMOVE_FILENAME) if file.is_file())
    team_files = {file.parent.name: file for file in points_to_remove_files}
    
    team_fieldnames = ['Team', 'Grade', 'Feedback']
    team_grades = {}
    for team_name, filename in team_files.items():
        with open(filename) as file:
            grade = POINTS_TOTAL
            lines = file.readlines()
            for line in lines:
                points_to_remove = float(line.split(':')[0])
                grade += points_to_remove

            team_grades[team_name] = {
                team_fieldnames[0]: team_name,
                team_fieldnames[1]: grade,
                team_fieldnames[2]: ''.join(lines)
            }

    individual_fieldnames = ['ID', 'FirstName', 'LastName', 'Email', 'Team', 'Grade', 'Feedback']
    individual_grades = []
    for team_info in teams_info:
        grade_info = team_info.copy()
        if team_info['Team'] in team_grades:
            grade_info.update(team_grades[team_info['Team']])
        else:
            grade_info['Grade'] = 0
            grade_info['Feedback'] = f'-{POINTS_TOTAL}: Aucun travail remis\n'
        individual_grades.append(grade_info)

    with open(GRADES_OUTPUT_FOLDER / 'team_grades.csv', 'w', newline='') as csv_file:
        writer = csv.DictWriter(csv_file, fieldnames=team_fieldnames)
        writer.writeheader()
        for row in sorted(team_grades.values(), key=lambda x: x[team_fieldnames[0]]):
            writer.writerow(row)
    
    with open(GRADES_OUTPUT_FOLDER / 'individual_grades.csv', 'w', newline='') as csv_file:
        writer = csv.DictWriter(csv_file, fieldnames=individual_fieldnames)
        writer.writeheader()
        for row in sorted(individual_grades, key=lambda x: x[individual_fieldnames[0]]):
            writer.writerow(row)


if __name__ == '__main__':
    main()
