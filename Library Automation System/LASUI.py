from BooksClass import *
from PeopleClass import *
from LASSupportSystems import *
from LASEntrySystems import *
from LASMainSystems import *
from abc import ABC, abstractmethod
from typing import Union


def main_ui() -> str:
    choice = input("""
        (R) Registration system

        (a) Enter from kiosk
        (b) Enter from web

        (E) exit
        Select: """)

    return choice


def registry_ui() -> str:
    choice = input("""
        (a) New user
        (b) Change password
        (c) Ask for a card
        (d) Delete account

        (E) exit
        Select: """)

    return choice


def enter_from_kiosk_ui(authorization_system, entry_system) -> tuple[str, People, bool]:
    member, flag = authorization_system.get_user()
    if not flag:
        return "e", member, flag

    flag = entry_system.enter_kiosk(member)

    if flag:
        choice = input("""
            (a) Browse library
            (b) Search for a book
            (c) Borrow book
            (d) Return book
            (f) Extend book period
            
            (E) exit
            Select: """)
    else:
        choice = "e"

    return choice, member, flag


def enter_from_web_ui(authorization_system, entry_system) -> tuple[str, People, bool]:
    member, flag = authorization_system.get_user()
    if not flag:
        return "e", member, flag

    flag = entry_system.enter_web(member)

    if flag:
        choice = input("""
            (a) Browse library
            (b) Search for a book
            (c) Extend book period

            (E) exit
            Select: """)
    else:
        choice = "e"

    return choice, member, flag


def new_user_ui(registration_database: LASRegistrationSystem) -> registry_ui:
    name = input("Enter user name: ")
    if name == "e":
        return

    flagRa = True
    while flagRa:
        for reg_member in registration_database.registered_users:
            if reg_member.name == name:
                flagRa = True
                print("User name already taken, please enter another name")
                name = input("Enter another user name: ")
                break
            else:
                flagRa = False

    password = input("Enter user password: ")
    membership = input("Are you a faculty member? (Y/N): ")

    if membership == "Y":
        member = FacultyMember(name, password, None)

    else:
        graduate = input("Are you a graduate student? (Y/N): ")

        if graduate == "Y":
            member = NonFacultyGraduate(name, password)

        else:
            member = NonFacultyMember(name, graduate)

    print("Successfully added the member")
    registration_database.register_user(member)

    return registry_ui


def change_password_ui(authorization_system: LASAuthorizationSystem) -> registry_ui:
    member, flag = authorization_system.get_user()

    if flag:
        new_password = input("Enter new password: ")
        print("Successfully changed your password")
        member.password = new_password
        return registry_ui
    else:
        return registry_ui


def give_card_ui(authorization_system: LASAuthorizationSystem, payment_system: LASPaymentSystem) -> registry_ui:
    member, flag = authorization_system.get_user()

    if member.has_card:
        print("You already have a card")
        return registry_ui
    else:
        if type(member) == NonFacultyGraduate:
            answer = input("You need to pay the annual fee for our card, proceed? (Y/N): ")
            if answer.upper() == "Y" and payment_system.get_entry_payment(member):
                print("Here is your card")
                member.has_card = True
                return registry_ui
            else:
                print("Sorry, we can't give you the card")
                return registry_ui
        else:
            print("Here is your card")
            member.has_card = True
            return registry_ui


def delete_account_ui(authorization_system: LASAuthorizationSystem, registration_system: LASRegistrationSystem) -> registry_ui:
    member, flag = authorization_system.get_user()

    if flag:
        registration_system.registered_users.remove(member)
        print("Account successfully deleted")
        return registry_ui
    else:
        return registry_ui


def browse_library_ui_kiosk(book_searching_system: LASBookSearching, library: list) -> enter_from_kiosk_ui:
    book_searching_system.show_library(library)
    return enter_from_kiosk_ui


def show_books_ui_kiosk(book_searching_system: LASBookSearching, library: list) -> enter_from_kiosk_ui:
    choice = input("""Search by Name (N), Author(A), Keyword (K)?: """)

    if choice.upper() == "N":
        book_searching_system.show_book_by_name(library)

    elif choice.upper() == "A":
        book_searching_system.show_book_by_author(library)

    elif choice.upper() == "K":
        book_searching_system.show_book_by_keyword(library)

    return enter_from_kiosk_ui


def lend_books_ui_kiosk(book_searching_system: LASBookSearching, book_lending_system: LASBookLending, library: list, member: People) -> enter_from_kiosk_ui:
    book_id = input("""Enter the id of the book you want to borrow: """)
    book = book_searching_system.search_book_by_id(book_id, library)

    if book.name == "e":
        print("We don't have that book")

    else:
        book_lending_system.lend_book(member, book)

    return enter_from_kiosk_ui


def retrieve_books_ui_kiosk(book_retrieving_system: LASBookRetrieval, member: People) -> enter_from_kiosk_ui:
    book_id = input("""Enter the id of the book you want to return: """)

    for book in member.possessions:
        if book.id == book_id:
            book_retrieving_system.retrieve_book(member, book)
            return enter_from_kiosk_ui

    print("You don't have that book")
    return enter_from_kiosk_ui


def extend_books_ui_kiosk(book_extending_system: LASBookExtension, member: People) -> enter_from_kiosk_ui:
    book_id = input("""Enter the id of the book you want to extend: """)

    for book in member.possessions:
        if book.id == book_id:
            if type(member) == FacultyMember:
                book_extending_system.faculty_extend_lending(member, book)
                return enter_from_kiosk_ui
            else:
                book_extending_system.extend_lending(member, book)
                return enter_from_kiosk_ui

    print("You don't have that book")
    return enter_from_kiosk_ui


def browse_library_ui_web(book_searching_system: LASBookSearching, library: list) -> enter_from_web_ui:
    book_searching_system.show_library(library)
    return enter_from_web_ui


def show_books_ui_web(book_searching_system: LASBookSearching, library: list) -> enter_from_web_ui:
    choice = input("""Search by Name (N), Author(A), Keyword (K)?: """)

    if choice.upper() == "N":
        book_searching_system.show_book_by_name(library)

    elif choice.upper() == "A":
        book_searching_system.show_book_by_author(library)

    elif choice.upper() == "K":
        book_searching_system.show_book_by_keyword(library)

    return enter_from_web_ui


def lend_books_ui_web(book_searching_system: LASBookSearching, book_lending_system: LASBookLending, library: list, member: People) -> enter_from_web_ui:
    book_id = input("""Enter the id of the book you want to borrow: """)
    book = book_searching_system.search_book_by_id(book_id, library)

    if book.name == "e":
        print("We don't have that book")

    else:
        book_lending_system.lend_book(member, book)

    return enter_from_kiosk_ui


def retrieve_books_ui_web(book_retrieving_system: LASBookRetrieval, member: People) -> enter_from_web_ui:
    book_id = input("""Enter the id of the book you want to return: """)

    for book in member.possessions:
        if book.id == book_id:
            book_retrieving_system.retrieve_book(member, book)
            return enter_from_web_ui

    print("You don't have that book")
    return enter_from_web_ui


def extend_books_ui_web(book_extending_system: LASBookExtension, member: People) -> enter_from_web_ui:
    book_id = input("""Enter the id of the book you want to extend: """)

    for book in member.possessions:
        if book.id == book_id:
            if type(member) == FacultyMember:
                book_extending_system.faculty_extend_lending(member, book)
                return enter_from_web_ui
            else:
                book_extending_system.extend_lending(member, book)
                return enter_from_web_ui

    print("You don't have that book")
    return enter_from_web_ui



