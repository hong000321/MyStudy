#include <iostream>

using namespace std;

void print(int& x)       { std::cout << "L-value\n"; }
void print(int&& x)      { std::cout << "R-value\n"; }

template<typename T>
void wrapper(T&& arg) {
    print(arg);   // ← 여기가 핵심!
}


int main(void){
    int a = 10;
    wrapper(a);     // ??? L-value인가?
    wrapper(10);    // ??? R-value인가?

    return 0;
}