from NumpyTest import NumpyTest as nt
from cpp import file as f
from cpp2 import sub as s
from PyClassTest import PyClassTest as p

if __name__ == '__main__':
    f.test() # Модуль cpp с функцией add
    s.test() # Модуль cpp2 с функцией sub
    p.test() # Модуль PyClassTest с классом и векторами
    nt.test() # Модуль NympyTest для работы с матрицами numpy


