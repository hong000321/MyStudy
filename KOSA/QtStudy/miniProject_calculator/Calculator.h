#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <QtTypes>

class Calculator
{


public:
    qreal prevResult;

    Calculator();
    qreal calc(qreal a, qreal b, uchar ch);


private:
    qreal a;
    qreal b;
    qreal resultValue;
    uchar ch;
    qreal add(qreal a, qreal b);
    qreal sub(qreal a, qreal b);
    qreal mul(qreal a, qreal b);
    qreal per(qreal a, qreal b);
    qreal div(qreal a, qreal b);
    qreal pow(qreal a, qreal b);

};

#endif // CALCULATOR_H
