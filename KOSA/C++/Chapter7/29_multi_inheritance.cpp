#include <iostream>
using namespace std;

class BaseOne{
public:
    void SimpleFuncOne(){ cout << "BaseOne" << endl; }
};

class BaseTwo{
public:
    void SimpleFuncTwo() { cout<<"BaseTwo"<<endl; }
};

class MultDerived: public BaseOne, protected BaseTwo{
public:
    void CompexFunc(){
        SimpleFuncOne();
        SimpleFuncTwo();
    }
};

int main(void){
    MultDerived mdr;
    mdr.CompexFunc();
    return 0;
}