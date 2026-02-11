#include <pybind11/pybind11.h>
#include <pybind11/stl.h> // НЕОБХОДИМАЯ строчка для того, чтобы pybind смог работать с векторами; работает автоматически
#include <locale.h>

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

// Не забываем подключить наш код
#include "ClassTest.h"


namespace py = pybind11;

// НАЗВАНИЕ МОДУЛЯ!!!
PYBIND11_MODULE(ClassTest, m, py::mod_gil_not_used()) {
    std::setlocale(LC_ALL, "Russian");

    m.doc() = R"pbdoc(
        Pybind11 example plugin
        -----------------------

        .. currentmodule:: ClassTest

        .. autosummary::
           :toctree: _generate

           ClassTest
    )pbdoc";

    // Классы подключаются по другому - с ними сложнее.
    //
    // Самое сложное - это конструкторы, к ним необходимо указывать не только названия аргументов, но и их тип.
    // Здесь 2 конструктора - один с типами int, int; второй с 2d вектором (вектор векторов) типа int - все это нужно прописать.
    //
    // Дальше указываеются методы и поля класса. Методы указываются также как и функции, нужно только указывать что они принадлежат этому классу.
    // Поля можно оформить через сеттеры и геттеры как функции, а можно сделать как тут - используя специальый синтаксис и ссылку на геттер,
    // открыть к ним достум в стиле python.

    // Название и ссылка на класс
    py::class_<ClassTest>(m, "ClassTest")

        .def(py::init<int, int>(),
            py::arg("n"), py::arg("m"))
        .def(py::init<std::vector<std::vector<int>>>(),
            py::arg("v"))

        .def_property_readonly("n", &ClassTest::getRows)
        .def_property_readonly("m", &ClassTest::getCols)
        .def_property_readonly("Data", &ClassTest::getData)


        .def("add", &ClassTest::add, py::arg("v"))
        .def("sub", &ClassTest::sub, py::arg("v"))
        ;

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}