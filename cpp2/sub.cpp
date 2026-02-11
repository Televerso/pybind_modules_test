#include <pybind11/pybind11.h>
#include <locale.h>

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

// Тут в качестве примера устанавливаем значения по умолчанию
int sub(int a = 20, int b = 2) {
    return a-b;
}

namespace py = pybind11;

// НАЗВАНИЕ МОДУЛЯ!!!
PYBIND11_MODULE(subTest, m, py::mod_gil_not_used()) {
    std::setlocale(LC_ALL, "Russian");

    m.doc() = R"pbdoc(
        Pybind11 example plugin
        -----------------------

        .. currentmodule:: subTest

        .. autosummary::
           :toctree: _generate

           sub
    )pbdoc";

    // Тогда и тут их тоже надо указать
    // Название и ссылка на функцию
    m.def("sub", &sub, R"pbdoc(
        Subtracts

    )pbdoc", py::arg("a") = 20, py::arg("b") = 2);

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}