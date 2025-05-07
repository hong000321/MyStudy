#include <stdio.h>
#define CIRCLE_AREA(R) (PRODUCT((R), (R))*PI)
#define PRODUCT(X, Y) ((X)*(Y))
#define PI 3.14159265358979


int main(void){
    double rad=2.2;
    printf("반지름 %g인 원의 넓이: %g \n", rad, CIRCLE_AREA(rad));
    
    return 0;
}