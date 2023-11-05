import sys
import smtplib
import ssl
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
from email.mime.base import MIMEBase
from email import encoders

def eliminateUnderScores(text):
    concat = ""
    for character in text: 
        if character == "_":
            concat += " "
        else:
            concat += character
    return concat

if len(sys.argv) > 1:
    # Variables
    sender_email = "sendEmailPersonalTest@gmail.com"
    password = "rybs tkaj yzis sduy"
    receiver_email = "fabriciosolisalpizar@gmail.com"

    subject = eliminateUnderScores(sys.argv[1])
    body = eliminateUnderScores(sys.argv[2])
    filename = sys.argv[3]

    # Email body creation
    message = MIMEMultipart()
    message["From"] = sender_email
    message["To"] = receiver_email
    message["Subject"] = subject

    message.attach(MIMEText(body, "plain"))

    # Attach File"
    attachment = open(filename, "rb")

    part = MIMEBase("application", "octet-stream")
    part.set_payload(attachment.read())

    encoders.encode_base64(part)
    part.add_header("Content-Disposition", f"attachment; filename= {filename}")

    message.attach(part)

    # SSL certificate 
    context = ssl.create_default_context()

    # Email Sender
    with smtplib.SMTP_SSL("smtp.gmail.com", 465, context=context) as server:
        server.login(sender_email, password)
        server.sendmail(sender_email, receiver_email, message.as_string())
else:
    print("Error handling email sending")