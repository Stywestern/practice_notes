from BooksClass import *
from PeopleClass import *
from typing import Union
from abc import ABC, abstractmethod

"""
Interfaces for Registration and Authorization 
"""


class AuthorizationSystem(ABC):

    @staticmethod
    @abstractmethod
    def get_user() -> tuple[People, bool]:
        pass

    @staticmethod
    @abstractmethod
    def check_kiosk(member: People) -> bool:
        pass

    @staticmethod
    @abstractmethod
    def check_web(member: People) -> bool:
        pass

    @staticmethod
    @abstractmethod
    def check_card(member: People) -> bool:
        pass


class RegistrationSystem(ABC):

    @abstractmethod
    def register_user(self, member: People) -> None:
        pass

    @staticmethod
    @abstractmethod
    def change_password(member: People) -> None:
        pass

    @staticmethod
    @abstractmethod
    def give_card(member: People) -> None:
        pass


class PaymentSystem(ABC):

    @staticmethod
    @abstractmethod
    def check_fee(self, member: People) -> int:
        pass

    @staticmethod
    @abstractmethod
    def get_entry_payment(member: People) -> bool:
        pass

    @staticmethod
    @abstractmethod
    def get_overdue_payment(member: People, book: Book) -> None:
        pass


"""
LAS support systems
"""


class LASRegistrationSystem(RegistrationSystem):

    registered_users = []

    def register_user(self, member: People) -> None:
        if member not in self.registered_users:
            self.registered_users.append(member)

        else:
            print("You are already registered")

    @staticmethod
    def change_password(member: People) -> None:
        new_password = input("Enter a password, it must be between 4 to 16 characters")
        while not len(new_password) in range(5, 16):
            new_password = input("The new password must be between 4 to 16 characters")

        member.password = new_password

    @staticmethod
    def give_card(member: People) -> None:
        member.has_card = True


class LASAuthorizationSystem(AuthorizationSystem):

    @staticmethod
    def get_user() -> tuple[People, bool]:
        name = input("Enter your user name or exit with 'e': ")
        if name == "e":
            return People("e", "e"), False

        flagRb = False
        i = 3
        for reg_member in REGISTRATION_DATABASE.registered_users:
            if reg_member.name == name:
                flagRb = True
                password = input("Enter your password: ")
                while i != 0:
                    i -= 1
                    if password == reg_member.password:
                        flagRb = True
                        member = reg_member
                        return member, True
                    else:
                        flagRb = False
                        password = input(f"Incorrect password, you have {i + 1} tries remaining: ")

            else:
                flagRb = False

        if i == 0:
            print("You have entered the wrong password too many times")
            return People("e", "e"), False

        elif not flagRb:
            print("You are not a registered user")
            return People("e", "e"), False

    @staticmethod
    def check_kiosk(member: People) -> bool:
        if member.kiosk_tokens == 0:
            print("You are out of kiosk tokens")
            return False
        else:
            print(f"Please proceed, you have {member.kiosk_tokens} kiosk tokens remaining")
            return True

    @staticmethod
    def check_web(member: People) -> bool:
        if member.web_tokens == 0:
            print("You are out of web tokens")
            return False
        else:
            print(f"Please proceed, you have {member.web_tokens} web tokens remaining")
            return True

    @staticmethod
    def check_card(member: People) -> bool:
        if member.has_card:
            return True
        else:
            print("Card not found, you should apply for a library card")
            return False


class LASPaymentSystem(PaymentSystem):

    @staticmethod
    def check_fee(member: Union[FacultyMember, NonFacultyMember], book: Book) -> int:
        if member.due_date < book.days_in_possession:
            weeks_passed = (book.days_in_possession - member.due_date) % 7
            fee = 10 + 20 * (weeks_passed - 1)
            return fee
        else:
            return 0

    @staticmethod
    def get_entry_payment(member: NonFacultyGraduate) -> bool:
        return True

    @staticmethod
    def get_overdue_payment(member: People, book: Book) -> None:
        """Customer pays"""
        print("Thank you, have a nice day")


REGISTRATION_DATABASE = LASRegistrationSystem()


