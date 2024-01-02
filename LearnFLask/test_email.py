import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart

email_user = 'hahnpartita@gmail.com'  # Replace with your Gmail username
email_pass = 'qkgp wwqa zkwp txhp'   # Replace with your Gmail password

with smtplib.SMTP('smtp.gmail.com', 587) as server:
    server.starttls()
    server.login(email_user, email_pass)
    
    # Create and send a test email
    msg = MIMEMultipart()
    msg['From'] = email_user
    msg['To'] = 'recipient@example.com'
    msg['Subject'] = 'Test Email'
    msg.attach(MIMEText('This is a test email.'))
    server.sendmail(email_user, 'recipient@example.com', msg.as_string())