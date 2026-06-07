from setuptools import find_packages
from setuptools import setup

setup(
    name='turret_control',
    version='0.0.0',
    packages=find_packages(
        include=('turret_control', 'turret_control.*')),
)
