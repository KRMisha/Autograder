#!/usr/bin/env python3

import csv
import getpass
import smtplib
import ssl
import sys
import config
from email.message import EmailMessage


def load_grades():
    if not config.INDIVIDUAL_GRADES_PATH.is_file():
        sys.exit('Error: individual grades file does not exist')

    with open(config.INDIVIDUAL_GRADES_PATH, newline='') as csv_file:
        reader = csv.DictReader(csv_file)
        return list(reader)


def send_emails(username, password, grades):
    context = ssl.create_default_context()
    with smtplib.SMTP(config.SMTP_SERVER, config.SMTP_PORT) as server:
        # Login
        server.ehlo()
        server.starttls(context=context)
        server.ehlo()
        server.login(username, password)

        # Send emails
        for grade in grades:
            print(f'Sending email to {grade["Email"]}')

            message = EmailMessage()
            message.set_content(
                config.EMAIL_CONTENT.format(
                    first_name=grade['FirstName'],
                    id=grade['ID'], team=grade['Team'],
                    grade=grade['Grade'],
                    points_total=config.POINTS_TOTAL,
                    feedback=grade['Feedback']
                )
            )

            message['Subject'] = config.EMAIL_SUBJECT
            message['From'] = config.SENDER_EMAIL
            message['To'] = grade['Email']

            server.send_message(message)


def main():
    grades = load_grades()

    username = input('Username: ')
    password = getpass.getpass()

    send_emails(username, password, grades)


if __name__ == '__main__':
    main()

# Made by Misha Krieger-Raynauld and Simon Gauvin
