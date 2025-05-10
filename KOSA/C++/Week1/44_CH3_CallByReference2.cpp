#include <iostream>

using namespace std;

int assignValue(int *n){
    *n = 10;
    return *n;
}

int main(void ){
    int num = 0, value;
    value = assignValue(&num);
    printf("[Input]: %d / : [Output]: %d \n", num, value);
    return 0;
}