import os

class Config:
    
    #SECRET_KEY = os.environ.get('SECRET_KEY')
    #SQLALCHEMY_DATABASE_URI = os.environ.get('SQLALCHEMY_DATABASE_URI')
    SECRET_KEY = '5791628bb0b13ce0c676dfde280ba245'
    SQLALCHEMY_DATABASE_URI= 'sqlite:///C:/Users/kerem/Desktop/VScode/LearnFLask/flask_app/instance/site.db'

    MAIL_SERVER = 'smtp.googlemail.com'
    MAIL_PORT = 587
    MAIL_USE_TLS = True

    email_user = 'hahnpartita@gmail.com'  
    email_pass = 'qkgp wwqa zkwp txhp' 

    #app.config['MAIL_USERNAME'] = os.environ.get('EMAIL_USER')
    #app.config['MAIL_PASSWORD'] = os.environ.get('EMAIL_PASS')

    