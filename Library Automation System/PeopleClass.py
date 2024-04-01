from typing import List, Type
from abc import ABC, abstractmethod

"""
Absract person class, baseline for customers
"""


class People(ABC):
    def __init__(self, name: str, password: str, possessions=None, has_card=False,
                 kiosk_tokens=3, web_tokens=3, book_capacity=3, due_date=15) -> None:
        self._possessions = possessions if possessions is not None else []
        self._name = name
        self._has_card = has_card
        self._password = password
        self._kiosk_tokens = kiosk_tokens
        self._web_tokens = web_tokens
        self._book_capacity = book_capacity
        self._due_date = due_date

    @property
    def password(self) -> str:
        return self._password

    @property
    def has_card(self) -> bool:
        return self._has_card

    @property
    def name(self) -> str:
        return self._name

    @property
    def possessions(self) -> List[Type["Book"]]:
        return self._possessions

    @property
    def kiosk_tokens(self) -> int:
        return self._kiosk_tokens

    @property
    def web_tokens(self) -> int:
        return self._web_tokens

    @property
    def book_capacity(self) -> int:
        return self._book_capacity

    @property
    def due_date(self) -> int:
        return self._due_date

    @abstractmethod
    def add_possessions(self, new_book: Type["Book"]) -> None:
        pass

    @abstractmethod
    def remove_possessions(self, new_book: Type["Book"]) -> None:
        pass

    @password.setter
    def password(self, new_password: str) -> None:
        self._password = new_password

    @has_card.setter
    def has_card(self, new_state: bool) -> None:
        self._has_card = new_state

    @kiosk_tokens.setter
    def kiosk_tokens(self, new_state: int) -> None:
        self._kiosk_tokens = new_state

    @web_tokens.setter
    def web_tokens(self, new_state: int) -> None:
        self._web_tokens = new_state

    def __str__(self) -> str:
        return f"People, {self.name}"

    def to_dict(self) -> dict:
        return {
            "type": self.__class__.__name__,
            "password": self._password,
            "name": self._name,
            "has_card": self._has_card,
            "possessions": self._possessions,
            "kiosk_tokens": self._kiosk_tokens,
            "web_tokens": self._web_tokens,
        }


"""
Concrete people
"""


class NonFacultyMember(People):
    def __init__(self, name: str, password: str, possessions=None, has_card=False,
                 kiosk_tokens=3, web_tokens=3, book_capacity=3, due_date=15) -> None:
        super().__init__(name, password, possessions, has_card, kiosk_tokens, web_tokens, book_capacity, due_date)

    def add_possessions(self, new_book: Type["NonClassMaterial"]) -> None:
        if len(self._possessions) < self._book_capacity:
            if not type(new_book) == Type["NonClassMaterial"]:
                print("The book is added to your library")
                self._possessions.append(new_book)
            else:
                print("The book you are trying to get doesn't exist")
        else:
            print("You reached the limit, you can't borrow anymore")

    def remove_possessions(self, pick_book: Type["NonClassMaterial"]) -> None:
        self.possessions.remove(pick_book)

    def __str__(self) -> str:
        return f"NonFacultyMember, {self.name}"

    def to_dict(self) -> dict:
        return {
            "type": self.__class__.__name__,
            "password": self._password,
            "name": self._name,
            "has_card": self._has_card,
            "possessions": self._possessions,
            "kiosk_tokens": self._kiosk_tokens,
            "web_tokens": self._web_tokens,
            "book_capacity": self._book_capacity,
            "due_date": self.due_date
        }


class NonFacultyGraduate(NonFacultyMember):
    def __init__(self, name: str, password: str, possessions=None, has_card=False,
                 kiosk_tokens=3, web_tokens=3, book_capacity=3, due_date=15) -> None:
        super().__init__(name, password, possessions, has_card, kiosk_tokens, web_tokens, book_capacity, due_date)

    def __str__(self) -> str:
        return f"NonFacultyGraduate, {self.name}"


class FacultyMember(People):
    def __init__(self, name: str, password: str, possessions: [], has_card=False,
                 kiosk_tokens=3, web_tokens=3, book_capacity=5, due_date=30) -> None:
        super().__init__(name, password, possessions, has_card, kiosk_tokens, web_tokens, book_capacity, due_date)

    def add_possessions(self, new_book: Type["Book"]) -> None:
        if len(self._possessions) < self._book_capacity:
            if not type(new_book) == Type["Book"]:
                print("The book is added to your library")
                self._possessions.append(new_book)
            else:
                print("The book you are trying to get doesn't exist")
        else:
            print("You reached the limit, you can't borrow anymore")

    def remove_possessions(self, pick_book: Type["Book"]) -> None:
        self.possessions.remove(pick_book)

    def __str__(self) -> str:
        return f"FacultyMember, {self.name}"

    def to_dict(self) -> dict:
        return {
            "type": self.__class__.__name__,
            "password": self._password,
            "name": self._name,
            "has_card": self._has_card,
            "possessions": self._possessions,
            "kiosk_tokens": self._kiosk_tokens,
            "web_tokens": self._web_tokens,
            "book_capacity": self._book_capacity,
            "due_date": self.due_date
        }

