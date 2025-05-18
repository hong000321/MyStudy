#include <stdio.h>

int factorial(int x){
    if(x <= 1)
        return 1;
    return x*factorial(x-1);
}

int main(void){
    int x = 5;
    int ret = factorial(x);

    printf("%d의 factorial은 %d입니다.\n",x,ret);

    return 0;
}