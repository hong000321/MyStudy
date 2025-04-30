#include <stdio.h>


float add(int n1, int n2){
    return n1+n2;
}
float minus(int n1, int n2){
    return n1-n2;
}
float mul(int n1, int n2){
    return n1*n2;
}
float div(int n1, int n2){
    return n1/n2;
}
float calc(int arg1, int arg2, float (* mat)(int n1, int n2)){
    return mat(arg1, arg2);
}

int main(void){
    int n1, n2;
    char op;
    float result;
    float (*funcPtr)(int n1, int n2);
    printf("입력 (x ? y): ");
    scanf("%d %c %d", &n1, &op, &n2);
    
    // printf("%d",(int)op);
    // printf("%d\n",(int)'*');


    switch (op)
    {
    case '+':
        funcPtr = add;
        break;
    case '-':
        funcPtr = minus;
        break;
    case '*':
        funcPtr = mul;
        break;
    case '/':
        funcPtr = div;
        break;
    
    default:
        break;
    }
    result = calc(n1,n2, funcPtr);
    printf("result = %f \n",result);
    return 0;
}