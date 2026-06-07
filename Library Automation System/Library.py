import json
from BooksClass import *
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

library = [
    ClassMaterial("AIN3780", "Intro to Medical AI", "Ümit", ["deep learning", "medical ai"], users[3].to_dict(), days_in_possession=40),
    ClassMaterial("AIN3781", "Intro to Medical AI", "Ümit", ["deep learning", "medical ai"], None),
    ClassMaterial("AIN3782", "Intro to Medical AI", "Ümit", ["deep learning", "medical ai"], None),
    ClassMaterial("INE2301", "Statistics for Engineers", "Tankut", ["statistics", "engineering"], None, days_in_possession=68),
    ClassMaterial("AIN3005", "Advanced Python", "Binnur", ["python", "advanced"], None),
    ClassMaterial("AIN3006", "Advanced Python", "Binnur", ["python", "advanced"], None),
    ClassMaterial("DER9301", "Science", "NASA", ["america", "space"], None, days_in_possession=10),
    ClassMaterial("DER7332", "Nature", "Scientist", ["science", "news"], None),
    NonClassMaterial("ED2000", "Huzur", "Ahmet Hamdi Tanpınar", ["melancholy", "character drama"], None),
    NonClassMaterial("ED3000", "Tutunamayanlar", "Oğuz Atay", ["loneliness", "postmodernism"], None, days_in_possession=20),
    NonClassMaterial("ED3001", "Tutunamayanlar", "Oğuz Atay", ["loneliness", "postmodernism"], None),
    NonClassMaterial("ED4000", "Kokoro", "Soseki", ["japan", "friendship"], None),
]


def book_to_dict(x):
    return x.to_dict()


library_data = list(map(book_to_dict, library))

# Serialize the library_data to JSON
library_json = json.dumps(library_data, indent=4)


# Write the JSON data to a file

with open("library.json", "w") as json_file:
    json_file.write(library_json)

LIBRARY = []


def update_library(json_path) -> list:
    with open(json_path, 'r') as file:
        data = json.load(file)

    books_list = []
    for entry in data:
        if entry['type'] == "NonClassMaterial":
            book = NonClassMaterial(entry['id'], entry['name'], entry['author'], entry['keywords'], entry['owner'],
                                    entry["days_in_possession"])
        elif entry['type'] == "ClassMaterial":
            book = ClassMaterial(entry['id'], entry['name'], entry['author'], entry['keywords'], entry['owner'],
                                 entry["days_in_possession"])
        else:
            book = "Not Found"
        books_list.append(book)
    return books_list




