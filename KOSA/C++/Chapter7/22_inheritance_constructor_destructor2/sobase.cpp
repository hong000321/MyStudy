#include "sobase.h"
#include <iostream>
using namespace std;

SoBase::SoBase() : baseNum(20){
    cout  << "SoBase()  Constructor" << endl;
}
SoBase::~SoBase(){
    cout  << "SoBase()  Destructor" << endl;
}
SoBase::SoBase(int n) : baseNum(n){
    cout << "SoBase(int n)  Constructor" << endl;
}
void SoBase::ShowBaseData(){
    cout << baseNum<<endl;
}

SoDerived::SoDerived() : derivNum(30){
    cout << "SoDerived()    Constructor" << endl;
}
SoDerived::~SoDerived(){
    cout << "SoDerived()    Destructor" << endl;
}
SoDerived::SoDerived(int n) : derivNum(n){
    cout << "SoDerived(int n)   Constructor" << endl;
}
SoDerived::SoDerived(int n1, int n2) : SoBase(n1), derivNum(n2){
    cout<< "SoDerived(int n1, int n2)   Constructor" << endl;
}
void SoDerived::ShowDerivData(){
    ShowBaseData();
    cout<<derivNum<<endl;
}





int main(void){
    cout << "..... case1 ..... " << endl;
    SoDerived dr1;
    dr1.ShowDerivData();
    cout << "..... case2 ..... " << endl;
    SoDerived dr2(12);
    dr2.ShowDerivData();
    cout << "..... case3 ..... " << endl;
    SoDerived dr3(23,24);
    dr3.ShowDerivData();


    return 0;
}