import os


if __name__ == '__main__':
    os.system("build.py build --build-lib=./lib")
    os.system("build.py install")

import subTest as s

def test():
    return s.sub(34,10)