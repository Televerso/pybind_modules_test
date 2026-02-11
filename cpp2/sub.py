import os


if __name__ == '__main__':
    os.system("build.py build --build-lib=./lib")
    os.system("build.py install")

import subTest as s

# Указываем только параметр b по имени
def test():
    print("Проверка модуля cpp2 : вычитание параметра по умолчанию (20) и переданного параметра b=10")
    print(s.sub(b = 10))
    print()