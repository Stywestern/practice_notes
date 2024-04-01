from typing import List, Type
from abc import ABC, abstractmethod


class Book(ABC):

    def __init__(self, id: str, name: str, author: str, keywords: [str],
                 owner: Type["People"], days_in_possession=0) -> None:
        self._id = id
        self._name = name
        self._owner = owner
        self._author = author
        self._keywords = keywords
        self._days_in_possession = days_in_possession

    @property
    def id(self) -> str:
        return self._id

    @property
    def name(self) -> str:
        return self._name

    @property
    def author(self) -> str:
        return self._author

    @property
    def owner(self) -> Type["People"]:
        return self._owner

    @property
    def keywords(self) -> list:
        return self._keywords

    @property
    def days_in_possession(self) -> int:
        return self.__days_in_possession

    @owner.setter
    def owner(self, new_owner: Type["People"]):
        self._owner = new_owner

    @days_in_possession.setter
    def days_in_possession(self, new_day: int):
        self._days_in_possession = new_day

    def to_dict(self):
        return {
            "type": self.__class__.__name__,
            "id": self._id,
            "name": self._name,
            "owner": self._owner,
            "author": self._author,
            "keywords": self._keywords,
            "days_in_possession": self._days_in_possession,
        }

    def __str__(self):
        return f"{self.name}, written by {self.author} (id: {self.id})"


class ClassMaterial(Book):
    def __init__(self, id: str, name: str, author: str, keywords: [str],
                 owner: Type["People"], days_in_possession=0) -> None:
        super().__init__(id, name, author, keywords, owner, days_in_possession)

    def __str__(self):
        return f"{self.__class__.__name__}, {self.name}, written by {self.author} (id: {self.id})"


class NonClassMaterial(Book):
    def __init__(self, id: str, name: str, author: str, keywords: [str],
                 owner: Type["People"], days_in_possession=0) -> None:
        super().__init__(id, name, author, keywords, owner, days_in_possession)

    def __str__(self):
        return f"{self.__class__.__name__}, {self.name}, written by {self.author} (id: {self.id})"




