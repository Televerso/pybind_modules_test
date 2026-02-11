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

    mat_eye = -np.eye(5)

    buffer = na.NumpyClassTest(6, 5)
    print(buffer.Data)
    print(buffer.add(image_start))
    print(buffer.sub(image_heart))
    print(buffer.mul(10))
    print(buffer.div(10))
    print(buffer.matMul(mat_eye))

    return buffer

