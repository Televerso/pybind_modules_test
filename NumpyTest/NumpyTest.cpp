#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <locale.h>

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

#include "NumpyClassTest.h"

namespace py = pybind11;



// НАЗВАНИЕ МОДУЛЯ!!!
PYBIND11_MODULE(NumpyAdder, m, py::mod_gil_not_used()) {
    std::setlocale(LC_ALL, "Russian");

    m.doc() = R"pbdoc(
        Pybind11 example plugin
        -----------------------

        .. currentmodule:: NumpyAdder

        .. autosummary::
           :toctree: _generate

           NumpyClassTest
    )pbdoc";


    // Название и ссылка на функцию
    py::class_<NumpyClassTest>(m, "NumpyClassTest")
        .def(py::init<int, int>(),
            py::arg("n"), py::arg("m"))
        .def(py::init<py::array_t<int>>(),
            py::arg("arr"))

        .def_property_readonly("n", &NumpyClassTest::getRows)
        .def_property_readonly("m", &NumpyClassTest::getCols)
        .def_property_readonly("Data", &NumpyClassTest::getData)


        .def("add", &NumpyClassTest::add, py::arg("arr"))
        .def("sub", &NumpyClassTest::sub, py::arg("arr"))
        .def("mul", &NumpyClassTest::mul, py::arg("n"))
        .def("div", &NumpyClassTest::div, py::arg("n"))
        .def("matMul", &NumpyClassTest::matMul, py::arg("arr"))
        ;

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}
