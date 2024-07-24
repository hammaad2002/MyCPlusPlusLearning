#include <pybind11/pybind11.h>

int add(int i, int j) {
    return i + j;
}

int subtract(int i, int j){
    return i - j;
}

PYBIND11_MODULE(example, m) {
    m.doc() = "Example module"; // optional module docstring
    m.def("add", &add, "A function which adds two numbers");
    m.def("sub", &subtract, "A function which subtracts two numbers");
}