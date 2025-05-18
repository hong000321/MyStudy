#include <iostream>
using namespace std;

template<typename T, typename R>
R MaxValue(const T num1, const R num2)
{
    if(num1>num2)
        return num1;
    else    
        return num2;
}