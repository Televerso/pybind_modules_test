import os

if __name__ == '__main__':
    os.system("build.py build --build-lib=./lib")
    os.system("build.py install")

import ClassTest as ct

def test():
    a = ct.ClassTest(2,2)
    print(a.Data)
    b = ct.ClassTest([[2,2],[1,1]])
    print(b.Data)
    print(a.sub(b.Data))

