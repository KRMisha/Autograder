#!/usr/bin/env python3

import csv
import getpass
import smtplib
import ssl
import time
from pathlib import Path

SENDER_EMAIL = 'misha.krieger-raynauld@polymtl.ca'
INDIVIDUAL_GRADES_FILENAME = Path('grades/individual_grades.csv')
POINTS_TOTAL = 20


def read_grades():
    with open(INDIVIDUAL_GRADES_FILENAME, newline='') as csv_file:
        reader = csv.DictReader(csv_file)
        return list(reader)


def send_email(username, password, receiver_email, subject, body):
    smtp_server = 'smtp.polymtl.ca'
    port = 587

    message = f'Subject: {subject}\n\n{body}'

    context = ssl.create_default_context()
    with smtplib.SMTP(smtp_server, port) as server:
        server.ehlo()
        server.starttls(context=context)
        server.ehlo()
        server.login(username, password)
        server.sendmail(SENDER_EMAIL, receiver_email, message.encode('utf8'))


def main():
    username = input('Poly username: ')
    password = getpass.getpass()

    grades = read_grades()

    for grade in grades:
        subject = 'Correction TP5 - Notes'
        body = (f'Bonjour {grade["FirstName"]},\n\n'
                 'Voici le détail de la correction pour le TP5. '
                 'Si vous avez des questions, vous pouvez répondre à ce courriel '
                 'et il me fera plaisir de vous expliquer.\n\n'
                 'Veuillez svp vérifier que les informations suivantes sont correctes:\n'
                f' - Matricule: {grade["ID"]}\n'
                f' - Binôme: {grade["Team"]}\n\n'
                f'Note: {grade["Grade"]}/{POINTS_TOTAL}\n\n'
                f'Détail de la correction:\n{grade["Feedback"]}\n'
                 'Passez un bon été et prenez soin de vous!\n\n'
                 'Misha')

        send_email(username, password, grade['Email'], subject, body)
        print(f'Sent email to {grade["Email"]}')
        time.sleep(10)


if __name__ == '__main__':
    main()
