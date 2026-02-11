#include <pybind11/pybind11.h>
#include <locale.h>

// Это нужно
#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

// C++ функция
int add(int a, int b) {
    return a+b;
}

// Задаем пространство имен
namespace py = pybind11;

// Код для связки - указывает pybind необходимую информацию о функциях
// НАЗВАНИЕ МОДУЛЯ!!!
PYBIND11_MODULE(bindTest, m, py::mod_gil_not_used()) {
    std::setlocale(LC_ALL, "Russian");

    // Описание модуля, которое будет видно из среды python
    m.doc() = R"pbdoc(
        Pybind11 example plugin
        -----------------------

        .. currentmodule:: bindTest

        .. autosummary::
           :toctree: _generate

           add
    )pbdoc";

    // Название и ссылка на функцию
    // Аргументы: 1. Название функции, которое будет видно из python; 2. Ссылка на функцию; 3. (Опционально) Описание функции;
    // 4. Перечисление аргументов функции, нужно для указания значений по умолчанию ил именной адресации.
    m.def("add", &add, R"pbdoc(
        Adds two numbers

    )pbdoc", py::arg("a"), py::arg("b"));

// Необходимые поля с указанием версии
#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}