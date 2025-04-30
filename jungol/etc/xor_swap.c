#include <stdio.h>

void xorSwap(int *a, int *b){
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

int main(void){
    int a = 18;
    int b = 27;
    
    xorSwap(&a,&b);
    printf("%d %d \n",a,b);
    return 0;
}