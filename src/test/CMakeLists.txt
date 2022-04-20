cmake_minimum_required(VERSION 2.8.12)
project(cmake_py2cpp)


add_subdirectory(pybind11)
pybind11_add_module(py2cpp py2cpp.cpp)