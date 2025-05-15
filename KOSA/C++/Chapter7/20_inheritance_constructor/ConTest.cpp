#include "ConTest.h"
#include <iostream>
using namespace std;


Con1::Con1(const int c)
{
    this->c=c;
    cout << "*** Con1의 생성자 ***" << endl;
    cout << "c=" << c << endl;
}

Con2::Con2(const int c) : Con1(c){
    cout << "*** Con2의 생성자 ***" << endl;
    return;
}

int main(){
    Con1 *p_TEST = new Con1(4);
    Con2 *p_TEST2 = new Con2(5);

    delete p_TEST;
    delete p_TEST2;

    return 0;
}
