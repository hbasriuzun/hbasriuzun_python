import smtplib
from email.mime.multipart import MIMEMultipart
from email.mime.base import MIMEBase
from email.mime.text import MIMEText
from email.utils import COMMASPACE
from email import encoders

# E-posta hesap bilgileri
mail_user = 'uzun.hbasri@gmail.com'
mail_password = 'fxgqjabnihhptnsn'
mail_send_to = 'basri.uzun@std.yildiz.edu.tr'

# E-posta oluşturma
msg = MIMEMultipart()
msg['From'] = mail_user
msg['To'] = COMMASPACE.join([mail_send_to])
msg['Subject'] = 'Word Belgesi Ektedir'

# Word belgesi ekleyin
filename = "Hasan_Basri_Uzun_CV_Türkçe.docx"
attachment = open("C:\\Users\\hbasr\\Desktop\\Mail\\Hasan_Basri_Uzun_CV_Türkçe.docx", "rb")
part = MIMEBase('application', 'octet-stream')
part.set_payload((attachment).read())
encoders.encode_base64(part)
part.add_header('Content-Disposition', "attachment; filename= %s" % filename)
msg.attach(part)

# E-posta gönderme
server = smtplib.SMTP('smtp.gmail.com', 587)
server.starttls()
server.login(mail_user, mail_password)
text = msg.as_string()
server.sendmail(mail_user, mail_send_to, text)
server.quit()

print('E-posta başariyla gönderildi.')