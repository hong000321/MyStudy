#ifndef VIRTUAL_CLASS_TEST2_H
#define VIRTUAL_CLASS_TEST2_H

#include <iostream>
#include <vector>
#include "virtual_class_test.h"


template <typename T>
class PrintTest{
private:
    std::vector<T> vec;
public:
    void print_all(Base* obj)
    {
        obj->print();
        Derived* derived = dynamic_cast<Derived*>(obj);
        if (derived)
        {
            derived->print_a();
            derived->print_b();
        }
    }
};



#endif







