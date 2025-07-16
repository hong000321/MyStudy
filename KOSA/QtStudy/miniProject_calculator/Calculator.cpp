#include "Calculator.h"
#include <stdio.h>
Calculator::Calculator(){
}


qreal Calculator::calc(qreal a, qreal b, uchar ch){
    switch (ch) {
    case '+':
        resultValue = add(a,b);
        break;
    case '-':
        resultValue = sub(a,b);
        break;
    case 'x':
        resultValue = mul(a,b);
        break;
    case '/':
        resultValue = div(a,b);
        break;
    case '^':
        resultValue = pow(a,b);
    case '%':
        resultValue = pow(a,b);
        break;
    case '=':
        resultValue = a;
        // empty
        break;
    }
    printf("%d\n",resultValue);
    return resultValue;
}

qreal Calculator::add(qreal a, qreal b){
    return a+b;
}

qreal Calculator::sub(qreal a, qreal b){
    return a-b;
}

qreal Calculator::mul(qreal a, qreal b){
    return a*b;
}

qreal Calculator::div(qreal a, qreal b){
    return a/b;
}

qreal Calculator::pow(qreal a, qreal b){
    qreal result = 1;
    for(int i=0;i<b;i++){
        result *= a;
    }
    return result;
}

qreal Calculator::per(qreal a, qreal b){
    return a*b/100;
}
