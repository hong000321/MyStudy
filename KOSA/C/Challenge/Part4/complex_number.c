#include <stdio.h>
#include <stdlib.h>

typedef struct complex_number
{
    float realn;
    float imgn;
} CompNumber;

CompNumber AddComp(CompNumber a, CompNumber b){
    CompNumber tmp;
    tmp.realn = a.realn + b.realn;
    tmp.imgn = a.imgn + b.imgn;
    return tmp;
}

CompNumber SubComp(CompNumber a, CompNumber b){
    CompNumber tmp;
    tmp.realn = a.realn - b.realn;
    tmp.imgn = a.imgn - b.imgn;
    return tmp;
}

CompNumber MulComp(CompNumber a, CompNumber b){
    CompNumber tmp;
    tmp.realn = a.realn * b.realn - a.imgn * b.imgn;
    tmp.imgn = a.imgn * b.realn + b.imgn * a.realn;
    return tmp;
}

CompNumber DivComp(CompNumber a, CompNumber b){
    CompNumber tmp;
    tmp.realn = a.realn*b.realn/(b.realn*b.realn+b.imgn*b.imgn);
    tmp.imgn =  a.imgn*b.imgn/(b.realn*b.realn+b.imgn*b.imgn);
    return tmp;
}

int main(void){
    CompNumber a,b,tmp;
    printf("복소수 입력1[실수 허수]: ");
    scanf("%f %f",&a.realn,&a.imgn);
    printf("복소수 입력2[실수 허수]: ");
    scanf("%f %f",&b.realn,&b.imgn);

    tmp = AddComp(a,b);
    printf("합의 결과] 실수 : %7.4f, 허수 : %7.4f\n",tmp.realn, tmp.imgn);

    tmp = SubComp(a,b);
    printf("뺀   결과] 실수 : %7.4f, 허수 : %7.4f\n",tmp.realn, tmp.imgn);
    
    tmp = MulComp(a,b);
    printf("곱한 결과] 실수 : %7.4f, 허수 : %7.4f\n",tmp.realn, tmp.imgn);
    
    tmp = DivComp(a,b);
    printf("나눈 결과] 실수 : %7.4f, 허수 : %7.4f",tmp.realn, tmp.imgn);
    return 0;
}
