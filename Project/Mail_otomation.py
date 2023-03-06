import os
from email.message import EmailMessage
import smtplib
import ssl

email_sender = 'uzun.hbasri@gmail.com'
email_password = os.environ.get('fxgqjabnihhptnsn')
email_receiver = 'basri.uzun@std.yildiz.edu.tr'

email_subject = 'Test'
email_body = 'Test'

msg = EmailMessage()
msg['Subject'] = email_subject
msg['From'] = email_sender
msg['To'] = email_receiver
msg.set_content(email_body)

context = ssl.create_default_context()

with smtplib.SMTP_SSL('smtp.gmail.com', 465,context=context) as smtp:
    smtp.login(email_sender, email_password)
    smtp.sendmail(email_sender, email_receiver, msg.as_string())
    


