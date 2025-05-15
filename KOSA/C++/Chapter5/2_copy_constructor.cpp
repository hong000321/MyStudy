#include <iostream>
using namespace std;

class Integer{
public:
    int *m_pInt;
    Integer(int value){
        m_pInt = new int;
        *m_pInt = value;
    }
    void printAddress() const {
        cout << "객체 주소: " << this << ", 값: " << *m_pInt << endl;
    }
};

int main(){
    Integer i1(3);
    // Integer i2(2);
    Integer i2 = i1;
    *i1.m_pInt = 11;
    i1.printAddress();
    i2.printAddress();
    printf("%p \n%p",&i1, &i2);
    return 0;
}