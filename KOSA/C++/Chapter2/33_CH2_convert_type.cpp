#include <stdio.h>
#include <math.h>

int main(){
    int i = 3.65;
    long l = M_PI;
    double f = M_PI;
    long double d = M_PI;

    printf("%d %d \n %.20lf\n %.20lf",i,l,f,d);

    return 0;
}