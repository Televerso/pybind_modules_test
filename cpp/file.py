import os


if __name__ == '__main__':
    os.system("build.py build --build-lib=./lib")
    os.system("build.py install")

import bindTest as m

def test():
    return m.add(1,1)
