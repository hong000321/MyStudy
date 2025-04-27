#include <stdio.h>

int main(void){
    int x1 = 0, x2 = 0;
    int x3, x4, x5, x6;

    scanf("%d %d",&x1,&x2);
    x3 = x1 * (x2%10);
    x4 = x1 * ((x2/10)%10);
    x5 = x1 * (x2/100);
    x6 = x1 * x2;

    printf("%d \n%d \n%d \n%d",x3,x4,x5,x6);

    return 0;
}