#include <pybind11/pybind11.h>
#include <locale.h>

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

int add(int a, int b) {
    return a+b;
}

namespace py = pybind11;


// НАЗВАНИЕ МОДУЛЯ!!!
PYBIND11_MODULE(bindTest, m, py::mod_gil_not_used()) {
    std::setlocale(LC_ALL, "Russian");

    m.doc() = R"pbdoc(
        Pybind11 example plugin
        -----------------------

        .. currentmodule:: bindTest

        .. autosummary::
           :toctree: _generate

           add
    )pbdoc";

    // Название и ссылка на функцию
    m.def("add", &add, R"pbdoc(
        Adds two numbers

    )pbdoc", py::arg("a"), py::arg("b"));

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}