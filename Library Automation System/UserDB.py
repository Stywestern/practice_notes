import json
from PeopleClass import *

users = [
NonFacultyMember("Tim", "password123", None),
NonFacultyMember("Burak", "pword123", None),
NonFacultyMember("Kerem", "word123", None, has_card=True),
FacultyMember("Mustafa", "pass", None, has_card=True),
FacultyMember("Binnur", "123", None, has_card=True),
FacultyMember("Tankut", "password123456", None),
NonFacultyGraduate("Sepideh", "cv123", None)
]


def people_to_dict(x):
    return x.to_dict()

user_data = list(map(people_to_dict, users))

# Serialize the library_data to JSON
users_json = json.dumps(user_data, indent=4)


# Write the JSON data to a file

with open("people.json", "w") as json_file:
    json_file.write(users_json)


def update_users(json_path):
    with open(json_path, 'r') as file:
        data = json.load(file)

    users_list = []
    for entry in data:
        if entry['type'] == "FacultyMember":
            person = FacultyMember(entry["name"], entry["password"], entry["possessions"], entry["has_card"],
                                   entry["kiosk_tokens"], entry["web_tokens"], entry["book_capacity"],
                                   entry["due_date"])
        elif entry['type'] == "NonFacultyMember":
            person = NonFacultyMember(entry["name"], entry["password"], entry["possessions"], entry["has_card"],
                                      entry["kiosk_tokens"], entry["web_tokens"], entry["book_capacity"],
                                      entry["due_date"])

        elif entry['type'] == "NonFacultyGraduate":
            person = NonFacultyGraduate(entry["name"], entry["password"], entry["possessions"], entry["has_card"],
                                        entry["kiosk_tokens"], entry["web_tokens"], entry["book_capacity"],
                                        entry["due_date"])
        else:
            person = "Not Found"

        users_list.append(person)

    return users_list

