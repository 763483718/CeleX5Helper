/*
 * @Descripttion: 
 * @version: 
 * @Author: guanzhou
 * @Date: 2021-01-09 10:33:14
 * @LastEditors: guanzhou
 * @LastEditTime: 2021-01-09 10:34:42
 */
#include <pybind11/pybind11.h>
#include <string>
#include <iostream>


class Hello
{
public:
    Hello(){}
    void say( std::string s );
};