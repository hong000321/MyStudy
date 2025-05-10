#include <iostream>

void Swap1(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


int main(){
    int a,b;
    a=10;
    b=20;
    Swap1(&a, &b);
    printf("a: %d b: %d",a,b);

    return 0;
}