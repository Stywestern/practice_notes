from BooksClass import *
from PeopleClass import *
from LASSupportSystems import *
from LASEntrySystems import *
from abc import ABC, abstractmethod

"""
Interfaces for lending, reservation and searching
"""


class BookLending(ABC):

    @staticmethod
    @abstractmethod
    def lend_book(member: People, book: Book) -> None:
        pass


class BookRetrieval(ABC):

    @staticmethod
    @abstractmethod
    def retrieve_book(member: People, book: Book) -> None:
        pass


class BookExtension(ABC):

    @staticmethod
    @abstractmethod
    def extend_lending(member: NonFacultyMember, book: Book) -> None:
        pass

    @staticmethod
    @abstractmethod
    def faculty_extend_lending(member: FacultyMember, book: Book) -> None:
        pass


class BookSearching(ABC):

    @staticmethod
    @abstractmethod
    def show_library(library: List[Book]) -> None:
        pass

    @staticmethod
    @abstractmethod
    def show_book_by_name(library: List[Book]) -> None:
        pass

    @staticmethod
    @abstractmethod
    def show_book_by_author(library: List[Book]) -> None:
        pass

    @staticmethod
    @abstractmethod
    def show_book_by_keyword(library: List[Book]) -> None:
        pass

    @staticmethod
    @abstractmethod
    def search_book_by_id(isbn: str, library: List[Book]) -> Book:
        pass


class BookReservation(ABC):

    @abstractmethod
    def check_library(self, library: List[Book]) -> bool:
        pass

    @abstractmethod
    def make_reservations(self, member: People, book: Book) -> None:
        pass

    @abstractmethod
    def notify_user(self, member: People, book: Book) -> None:
        pass


"""
LAS main systems
"""

"""Book lending"""


class LASBookLending(BookLending):

    @staticmethod
    def lend_book(member: People, book: Book) -> None:
        if type(book) == ClassMaterial:
            if type(member) == FacultyMember:
                if book.owner is None:
                    member.add_possessions(book)
                    book.owner = member

                elif book.owner == member:
                    print("You already borrowed this")

                else:
                    answer = input("The material is borrowed, would you like a reservation(Y/N)?: ")
                    if answer.upper() == "Y":
                        LASBookReservation.make_reservations(RESERVATION_DATABASE, member, book)
                    else:
                        return
            else:
                print("Only faculty members can borrow class materials")

        else:
            if book.owner is None:
                member.add_possessions(book)
                book.owner = member

            elif book.owner == member:
                print("You already borrowed this")

            else:
                answer = input("The material is borrowed, would you like a reservation(Y/N)?: ")
                if answer.upper() == "Y":
                    LASBookReservation.make_reservations(RESERVATION_DATABASE, member, book)
                else:
                    return


"""Book retrieval"""


class LASBookRetrieval(BookRetrieval):

    def retrieve_book(self, member: People, book: Book) -> None:
        if book in member.possessions:
            member.remove_possessions(book)
            book.owner = None
            print(f"Book returned after {book.days_in_possession} days")

            fee = LASPaymentSystem.check_fee(member, book)
            if fee:
                print(f"You need to pay {fee} for overdue")
                LASPaymentSystem.get_overdue_payment(member, book)
            else:
                print("Have a nice day")

        else:
            print("You don't own that book")


"""Book extension"""


class LASBookExtension(BookExtension):
    def extend_lending(self, member: NonFacultyMember, book: NonClassMaterial) -> None:
        if book.days_in_possession > member.due_date:
            print("It's passes the due date, you can't extend anymore")

        else:
            book.days_in_possession -= member.due_date
            print(f"Due date is extended by {member.due_date} days")

    def faculty_extend_lending(self, member: FacultyMember, book: Book) -> None:
        if book.days_in_possession > member.due_date:
            print("It's passes the due date, you can't extend anymore")

        else:
            if type(book) == ClassMaterial:
                extension = 180-book.days_in_possession
                book.days_in_possession -= extension
                print(f"Due date is extended by {extension} days")
            else:
                book.days_in_possession -= member.due_date
                print(f"Due date is extended by {member.due_date} days")


"""Book Searching"""


class LASBookSearching(BookSearching):

    @staticmethod
    def show_library(library: List[Book]) -> None:
        print("#############################################")
        for book in library:
            print(book)
        print("#############################################")

    @staticmethod
    def show_book_by_name(library: List[Book]) -> None:
        name = input("Search name: ")
        printing_list = []

        for book in library:
            if name == book.name:
                printing_list.append(book)

        if len(printing_list) == 0:
            print("Looks like there is no book by that name here")
            return

        print(f"{len(printing_list)} matches found: ")
        for book in printing_list:
            print(f"{book} " if book.owner is None else f"(Owned) {book}")

    @staticmethod
    def show_book_by_author(library: List[Book]) -> None:
        author = input("Search author: ")
        printing_list = []

        for book in library:
            if author == book.author:
                printing_list.append(book)

        if len(printing_list) == 0:
            print("Looks like there is no book with that author here")
            return

        print(f"{len(printing_list)} matches found: ")
        for book in printing_list:
            print(f"{book}" if book.owner is None else f"(Owned) {book})")

    @staticmethod
    def show_book_by_keyword(library: List[Book]) -> None:
        keyword = input("Search keyword: ")
        printing_list = []

        for book in library:
            if keyword in book.keywords:
                printing_list.append(book)

        if len(printing_list) == 0:
            print("Looks like there is no book with that author here")
            return

        print(f"{len(printing_list)} matches found: ")
        for book in printing_list:
            print(f"{book}" if book.owner is None else f"(Owned) {book})")

    @staticmethod
    def search_book_by_id(isbn: str, library: List[Book]) -> Book:
        for book in library:
            if book.id == isbn:
                return book

        return Book("e", "e", "e", "e", "e")


"""Book Reservation"""


class LASBookReservation(BookReservation):
    reserved_books = {"INE2301": "Tankut"}

    def check_library(self, library: List[Book]) -> bool:
        for book in library:
            if book.id in self.reserved_books.keys():
                return True

        return False

    def make_reservations(self, member: People, book: Book) -> None:
        if book.id in self.reserved_books.keys():
            print(f"Sorry, the book already reserved by {self.reserved_books[book.id]}")
        else:
            print("Successfully reserved under your name")
            self.reserved_books[book.id] = member.name

    def notify_user(self, member: People, book: Book) -> None:
        """Runs on some sort of internal clock"""

        if book.id in self.reserved_books.keys():
            pass
            """ Notifies the user """


RESERVATION_DATABASE = LASBookReservation()


