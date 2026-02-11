from setuptools import setup, Extension
import pybind11

__version__ = "0.0.1"

ext_modules = [
    Extension(
        'ClassTest', # НАЗВАНИЕ МОДУЛЯ!!!
        ['PyClassTest.cpp'],
        include_dirs=[pybind11.get_include()],
        language='c++',
        extra_compile_args=['-std=c++11'],
    ),
]

setup(
    name='ClassTest', # имя библиотеки собранной pybind11 # НАЗВАНИЕ МОДУЛЯ!!!
    version=__version__,
    author='tele',
    author_email='tele@inbox.ru',
    description='pybind11 extension',
    ext_modules=ext_modules,

    requires=['pybind11'],
    package_dir = {'': 'lib'}
)