from setuptools import setup, Extension
import pybind11

__version__ = "0.0.1"

ext_modules = [
    Extension(
        'bindTest', # НАЗВАНИЕ МОДУЛЯ!!!
        ['file.cpp'], # Список (!) .cpp файлов для компиляции
        include_dirs=[pybind11.get_include()], # Обязательно
        language='c++',
    ),
]

setup(
    name='bindTest', # имя библиотеки собранной pybind11 # НАЗВАНИЕ МОДУЛЯ!!!
    version=__version__, # версия из переменной выше
    author='tele', # автор
    author_email='tele@inbox.ru',
    description='pybind11 extension', # Описание
    ext_modules=ext_modules, # Обязательно

    requires=['pybind11'], # Список необходимых библиотек python
    package_dir = {'': 'lib'} # Папка с полученным модулем
)