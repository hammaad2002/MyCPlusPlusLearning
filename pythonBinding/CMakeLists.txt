cmake_minimum_required(VERSION 3.22)

project(example)

set(CMAKE_CXX_STANDARD 11)

find_package(pybind11 REQUIRED)

pybind11_add_module(example example.cpp)

# project(example)

# # How to create a variable
# set(VENV "${CMAKE_CURRENT_BINARY_DIR}/myvenv")

# # Specify the python executable in the virtual environment
# set(PYTHON_EXECUTABLE "${VENV}/bin/python")

# # Prioritize finding Python in the virtual environment
# set(Python_VIRTUALENV FIRST)

# # Find Python
# find_package(Python 3 REQUIRED COMPONENTS Interpreter Development)

# Find pybind11
# find_package(pybind11 REQUIRED)

# pybind11_add_module(example example.cpp)