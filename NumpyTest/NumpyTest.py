import os
import numpy as np

if __name__ == '__main__':
    os.system("build.py build --build-lib=./lib")
    os.system("build.py install")

import NumpyAdder as na

def test():
    image_start = np.array([
        [1, 1, 1, 1, 1],
        [1, 1, 1, 1, 1],
        [1, 1, 1, 1, 1],
        [1, 1, 1, 1, 1],
        [1, 1, 1, 1, 1],
        [1, 1, 1, 1, 1],
    ])

    image_heart = np.array([
        [0, 1, 0, 1, 0],
        [1, 0, 1, 0, 1],
        [1, 0, 0, 0, 1],
        [1, 0, 0, 0, 1],
        [0, 1, 0, 1, 0],
        [0, 0, 1, 0, 0],
    ])

    mat_column = np.array([
        [1],
        [2],
        [3],
        [4],
        [5],
    ])

    mat_mat = np.array([
        [1, 1, 1, 1, 2, 0],
        [1, 1, 1, 2, 1, 0],
        [1, 1, 2, 1, 1, 0],
        [1, 2, 1, 1, 1, 0],
        [2, 1, 1, 1, 1, 0],
    ])

    mat_eye = np.eye(5)

    print("Проверка модуля NumpyTest : работа с массивами numpy")

    buffer = na.NumpyClassTest(6, 5) # Помним, что в нашей структуре данных массив numpy хранится как одно из полей
    print("Матрица 6х5, заполненный нулями:")
    print(buffer.Data)
    print("Проверка сложения матриц")
    print(buffer.add(image_start))
    print("Проверка вычитания матриц")
    print(buffer.sub(image_heart))
    print("Проверка умножения матрицы на скаляр")
    print(buffer.mul(10))
    print("Проверка деления матрицы на скаляр")
    print(buffer.div(10))
    print("Проверка умножения на единичную матрицу")
    print(buffer.matMul(mat_eye))
    print("Проверка умножения на столбец")
    print(buffer.matMul(mat_column))
    print()
    return buffer

