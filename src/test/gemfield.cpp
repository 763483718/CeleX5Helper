/*
 * @Descripttion: 
 * @version: 
 * @Author: guanzhou
 * @Date: 2021-01-08 20:28:51
 * @LastEditors: guanzhou
 * @LastEditTime: 2021-01-08 20:46:43
 */
//gemfield.cpp
#include <pybind11/pybind11.h>

int add(int i, int j) {
    return i + j;
}

PYBIND11_MODULE(gemfield, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring
    m.def("add", &add, "A function which adds two numbers");
}
