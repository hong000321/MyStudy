#include <iostream>


int main(void){
    int a = 11;
    int *p = &a;
    int &r1 = a;
    int &&r2 = 10;

    printf("a   : %p\n", &a);
    printf("ap  : %p\n", p);
    printf("p   : %p\n", &p);
    printf("r1  : %p\n", &r1);
    printf("r2  : %p\n", &r2);

    return 0;
}