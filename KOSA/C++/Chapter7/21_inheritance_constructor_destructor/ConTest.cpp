#include "ConTest.h"
#include <iostream>
using namespace std;


Con1::Con1(const int c)
{
    this->c=c;
    cout << "*** Con1의 생성자 ***" << this << endl;
    cout << "c=" << c << endl;
}
Con1::~Con1()
{
    cout << "*** Con1의 소멸자 ***" << this <<endl;
}

Con2::Con2(const int c) : Con1(c){
    cout << "*** Con2의 생성자 ***" << this << endl;
    cout << "c=" << c << endl;
    return;
}
Con2::~Con2()
{
    cout << "*** Con2의 소멸자 ***" << this << endl;
}

int main(){
    Con1 *p_TEST = new Con1(4);
    Con2 *p_TEST2 = new Con2(5);

    delete p_TEST;
    delete p_TEST2;

    return 0;
}
