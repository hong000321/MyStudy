#include <stdio.h>


int main(void){
    
    long long int y3;
    long long int x3 = -9223372036854775808;
    y3 = -x3;
    printf("%10lld  %10lld\n   ", x3, y3);
    if(x3 == y3) printf("1");
    if((x3-y3) == 0) printf("2");
    if((x3+y3) == 2*y3) printf("3");
    if(x3 != -y3) printf("4");
    printf("\n");
    
    int y;
    int x = -2147483648;
    y = -x;
    printf("%10d  %10d\n   ", x, y);
    if(x == y) printf("1");
    if((x-y) == 0) printf("2");
    if((x+y) == 2*y) printf("3");
    if(x != -y) printf("4");
    printf("\n");

    short y1;
    short x1 = -32768;
    y1 = -x1;
    printf("%10d  %10d\n   ", x1, y1);
    if(x1 == y1) printf("1");
    if((x1-y1) == 0) printf("2");
    if((x1+y1) == 2*y1) printf("3");
    if(x1 != -y1) printf("4");
    printf("\n");

    char y2;
    char x2 = -128;
    y2 = -x2;
    printf("%10d  %10d\n   ", x2, y2);
    if(x2 == y2) printf("1");
    if((x2-y2) == 0) printf("2");
    if((x2+y2) == 2*y2) printf("3");
    if(x2 != -y2) printf("6");
    printf("\n");

    return 0;
}
