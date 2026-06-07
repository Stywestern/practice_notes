from BooksClass import *
from PeopleClass import *
from LASSupportSystems import *
from abc import ABC, abstractmethod

"""Interfaces for entry systems"""


class KioskSystem(ABC):

    @staticmethod
    @abstractmethod
    def enter_kiosk(member: People) -> bool:
        pass


class WebSystem(ABC):

    @staticmethod
    @abstractmethod
    def enter_web(member: People) -> bool:
        pass


"""LAS entry systems"""


class LASKioskSystem(KioskSystem):

    @staticmethod
    def enter_kiosk(member: People) -> bool:
        if member.name == "e":
            return False

        if LASAuthorizationSystem.check_card(member):
            if LASAuthorizationSystem.check_kiosk(member):
                member.kiosk_tokens -= 1
                return True

            else:
                print("Out of token, you can't benefit from kiosk services")
                return False
        else:
            print("You need a library card for kiosk services")
            return False


class LASWebSystem(WebSystem):

    @staticmethod
    def enter_web(member: People) -> bool:
        if member.name == "e":
            return False

        if LASAuthorizationSystem.check_card(member):
            if LASAuthorizationSystem.check_web(member):
                member.web_tokens -= 1
                return True
            else:
                print("Out of token, you can't benefit from web services")
                return False
        else:
            print("You need a library card for web services")
            return False
