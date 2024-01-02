from flask_app import app, db
from flask_app.models import User, Post

with app.app_context():
    db.create_all()