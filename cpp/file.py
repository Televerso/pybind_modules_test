import os

# При запуске файла напрямую перекомпилируем модуль
if __name__ == '__main__':
    os.system("build.py build --build-lib=./lib")
    os.system("build.py install")

# Подключаем его
import bindTest as m

# Функция для проверки модуля
def test():
    print("Проверка модуля cpp : сложение 1+1")
    print(m.add(1,1))
    print()
