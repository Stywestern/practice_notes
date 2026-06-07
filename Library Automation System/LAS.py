from BooksClass import *
from PeopleClass import *
from LASSupportSystems import *
from LASEntrySystems import *
from LASMainSystems import *
from LASUI import *
from Library import *
from UserDB import *
from abc import ABC, abstractmethod
import json

""" Database """
LIBRARY.extend(update_library('library.json'))
REGISTRATION_DATABASE.registered_users.extend(update_users('people.json'))

""" Interfaces """
authorization_system = LASAuthorizationSystem()
payment_system = LASPaymentSystem()
kiosk_entry_system = LASKioskSystem()
web_entry_system = LASWebSystem()

book_searching_system = LASBookSearching()
book_lending_system = LASBookLending()
book_retrieval_system = LASBookRetrieval()
book_extending_system = LASBookExtension()

choice1 = main_ui()

while choice1.capitalize() != "E":
    if choice1.capitalize() == "R":
        choice2 = registry_ui()
        while choice2.capitalize() != "E":
            if choice2.lower() == "a":
                choice2 = new_user_ui(REGISTRATION_DATABASE)()

            elif choice2.lower() == "b":
                choice2 = change_password_ui(authorization_system)()

            elif choice2.lower() == "c":
                choice2 = give_card_ui(authorization_system, payment_system)()

            elif choice2.lower() == "d":
                choice2 = delete_account_ui(authorization_system, REGISTRATION_DATABASE)()

        choice1 = main_ui()

    elif choice1.lower() == "a":
        choice3, member, flag = enter_from_kiosk_ui(authorization_system, kiosk_entry_system)
        if flag:
            while choice3.capitalize() != "E":
                if choice3.lower() == "a":
                    choice3, member, flag = browse_library_ui_kiosk(book_searching_system, LIBRARY)(authorization_system, kiosk_entry_system)

                elif choice3.lower() == "b":
                    choice3, member, flag = show_books_ui_kiosk(book_searching_system, LIBRARY)(authorization_system, kiosk_entry_system)

                elif choice3.lower() == "c":
                    choice3, member, flag = lend_books_ui_kiosk(book_searching_system, book_lending_system, LIBRARY, member)(authorization_system, kiosk_entry_system)

                elif choice3.lower() == "d":
                    choice3, member, flag = retrieve_books_ui_kiosk(book_retrieval_system, member)(authorization_system, kiosk_entry_system)

                elif choice3.lower() == "f":
                    choice3, member, flag = extend_books_ui_kiosk(book_extending_system, member)(authorization_system, kiosk_entry_system)

            choice1 = main_ui()
        else:
            choice1 = main_ui()

    elif choice1.lower() == "b":
        choice3, member, flag = enter_from_web_ui(authorization_system, web_entry_system)
        if flag:
            while choice3.capitalize() != "E":
                if choice3.lower() == "a":
                    choice3, member, flag = browse_library_ui_web(book_searching_system, LIBRARY)(authorization_system, web_entry_system)

                elif choice3.lower() == "b":
                    choice3, member, flag = show_books_ui_web(book_searching_system, LIBRARY)(authorization_system, web_entry_system)

                elif choice3.lower() == "f":
                    choice3, member, flag = extend_books_ui_web(book_extending_system, member)(authorization_system, web_entry_system)

            choice1 = main_ui()
        else:
            choice1 = main_ui()

    else:
        exit()


for user in REGISTRATION_DATABASE.registered_users:
    print(f"{user}, {user.password}, {user.has_card}")

print("----------------------------------------------------")

for book in LIBRARY:
    print(f"{book}, {book.owner}, {book.days_in_possession}")

print("----------------------------------------------------")

for book_id in RESERVATION_DATABASE.reserved_books:
    print(f"{book_id} {RESERVATION_DATABASE.reserved_books[book_id]}")

print("----------------------------------------------------")
print("End")



