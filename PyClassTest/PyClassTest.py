import os

if __name__ == '__main__':
    os.system("build.py build --build-lib=./lib")
    os.system("build.py install")

import ClassTest as ct

def test():
    print("Проверка модуля PyClassTest : базовая работа с векторами")

    # Создаем вектор нулей размера 2х2
    a = ct.ClassTest(2,2)
    print("A = 2D список 2х2, заполненный нулями")
    print(a.Data)
    # Создаем вектор с указанными значениями
    b = ct.ClassTest([[2,2],[1,1]])
    print("B = 2D список 2х2 с произвольными значениями")
    print(b.Data)
    print("A - B = ")
    print(a.sub(b.Data))
    print()
