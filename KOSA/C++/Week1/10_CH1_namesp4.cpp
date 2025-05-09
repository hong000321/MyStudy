#include <iostream>

int data = 10;


void Func() {}

namespace X{
    int data = 20;
    void Func();
}

int main(){
    using namespace X;
    int data =30;
    std::cout << "data = " << data << "\n";
    std::cout << "X::data = " << X::data << "\n";
    std::cout << "::data = " << ::data << "\n";
    return 0;
}


