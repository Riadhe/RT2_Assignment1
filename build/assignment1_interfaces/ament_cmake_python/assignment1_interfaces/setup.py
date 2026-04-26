from setuptools import find_packages
from setuptools import setup

setup(
    name='assignment1_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('assignment1_interfaces', 'assignment1_interfaces.*')),
)
