/*
 * @Descripttion: 
 * @version: 
 * @Author: guanzhou
 * @Date: 2021-01-08 21:36:22
 * @LastEditors: guanzhou
 * @LastEditTime: 2021-01-08 21:38:22
 */
#include<string>
#include<pybind11/pybind11.h>
class CivilNet {
    public:
        CivilNet(const std::string &name) : name_(name) { }
        void setName(const std::string &name) { name_ = name; }
        const std::string &getName() const { return name_; }
    private:
        std::string name_;
};


PYBIND11_MODULE(syszux, m) {
    pybind11::class_<CivilNet>(m, "CivilNet")
        .def(pybind11::init<const std::string &>())
        .def("setName", &CivilNet::setName)
        .def("getName", &CivilNet::getName);
}

// g++ -O3 -Wall -shared -std=c++11 -fPIC `python3 -m pybind11 --includes` CivilNet.cpp -o syszux`python3-config --extension-suffix`