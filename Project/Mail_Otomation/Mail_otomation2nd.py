from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
import smtplib
print("Hello World")
message = MIMEMultipart()
message["from"] = "Hasan Basri Uzun"
message["to"] = "basri.uzun@std.yildiz.edu.tr"
message["subject"] = "Test"
message.attach(MIMEText("Test"))

with smtplib.SMTP(host="smtp.gmail.com", port=587) as smtp:
    smtp.ehlo()
    smtp.starttls()
    smtp.login("uzun.hbasri@gmail.com", "fxgqjabnihhptnsn")
    smtp.send_message(message)  
    print("Sent...")