from flask_app import app, db
from flask_app.models import User, Post
import json

with open(r'C:\Users\kerem\Desktop\VScode\LearnFLask\posts.json', 'r') as file:
    posts_data = json.load(file)

    with app.app_context():
        for post_data in posts_data:
            new_post = Post(
                title=post_data['title'],
                content=post_data['content'],
                user_id=post_data['user_id'],
                # Add other fields as needed
            )

            db.session.add(new_post)

        # Commit the changes to the database
        db.session.commit()