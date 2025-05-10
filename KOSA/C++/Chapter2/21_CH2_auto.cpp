#include <iostream>


using namespace std;


int main(void){
    int n = 1234;
    double d= 1.231;
    char c = 'A';
    string s = "test" ;
    auto autoVar1 = d;
    auto autoVar2 = n;
    auto autoVar3 = n+d;
    auto autoVar4 = c+n;
    auto autoVar5 = c+d;
    auto autoVar6 = s+c;
    autoVar3 = 1;

    cout <<autoVar1 << endl;
    cout <<autoVar2 << endl;
    cout <<autoVar3 << "   " << sizeof(autoVar3)<< endl;
    cout <<autoVar4 << "   " << sizeof(autoVar4) << endl;
    cout <<autoVar5 << endl;
    cout <<autoVar6 << endl;

    return 0;
}