#ifndef VIRTUAL_CLASS_TEST_H
#define VIRTUAL_CLASS_TEST_H
#include <iostream>

class Base
{
public:
    virtual void print();
};


class Derived : public Base
{
private:
    int a = 10;
    int b = 20;
public:
    void print() override
    {
        std::cout << "Derived" << std::endl;
    }
    void print_a()
    {
        std::cout << "a: " << a << std::endl;
    }
    void print_b()
    {
        std::cout << "b: " << b << std::endl;
    }
};


#endif