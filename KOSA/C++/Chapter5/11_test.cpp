#include <iostream>


double foo(double a){
    return a;
}

int main(void){
    int a(10);
    int b{10};
    int c[10];

    int d(10.0);

    int f;
    f = foo({5.0});


    return 0;
}