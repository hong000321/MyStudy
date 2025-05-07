#include <stdio.h>
#define ADD(A,B,C) (A)+(B)+(C)
#define MUL(A,B,C) (A)*(B)*(C)
#define PI 3.141592
#define AREA(A) (A)*(A)*PI
#define MAX(A,B) ((A)>(B)?(A):(B))

int main(void){
    int a,b,c;
    scanf("%d %d %d",&a, &b, &c);
    printf("p1 : %d %d \n",ADD(a,b,c),MUL(a,b,c));
    printf("p2 : %d\n",AREA(10));
    printf("p3 : %d\n",MAX(18,39));

    return 0;
}