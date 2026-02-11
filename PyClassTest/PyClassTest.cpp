#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <locale.h>

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

#include "ClassTest.h"


namespace py = pybind11;

// НАЗВАНИЕ МОДУЛЯ!!!
PYBIND11_MODULE(ClassTest, m, py::mod_gil_not_used()) {
    std::setlocale(LC_ALL, "Russian");

    m.doc() = R"pbdoc(
        Pybind11 example plugin
        -----------------------

        .. currentmodule:: bindTest

        .. autosummary::
           :toctree: _generate

           ClassTest
    )pbdoc";

    // Название и ссылка на функцию
    py::class_<ClassTest>(m, "ClassTest")
        .def(py::init<int, int>(),
            py::arg("n"), py::arg("m"))
        .def(py::init<std::vector<std::vector<int>>&>(),
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