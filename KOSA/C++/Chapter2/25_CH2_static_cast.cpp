#include <iostream>

using namespace std;


int main(void){
    float i = 100.12345;
    double j = 200.12345;
    float count = static_cast<float>(j/i);

    double d = 1212;
    void *p = &d;
    double *dp = static_cast<double*>(p);

    double d2 = 4.24;
    // int *i1 = (int *)&d2;                //컴파일은 되지만, 언젠가 에러 유발함.
    // int * i2 = static_cast<int *>(&d2);  // 컴파일 에러
    // int i3 = dynamic_csst<int>(d2);      // 컴파일 에러, 기본 자료형 안됨


    return 0;
}