/*
 * @Descripttion: 
 * @version: 
 * @Author: guanzhou
 * @Date: 2021-01-08 20:55:35
 * @LastEditors: guanzhou
 * @LastEditTime: 2021-01-09 10:36:37
 */

#include "py2cpp.h"

void Hello::say(std::string s){
    std::cout<<s<<std::endl;
}

PYBIND11_MODULE( py2cpp, m ){
    m.doc() = "pybind11 example";

    pybind11::class_<Hello>(m, "Hello" )
        .def(pybind11::init())
        .def( "say", &Hello::say );
}


// g++ -O3 -Wall -shared -std=c++11 -fPIC `python3 -m pybind11 --includes` py2cpp.cpp -o py2cpp`python3-config --extension-suffix`