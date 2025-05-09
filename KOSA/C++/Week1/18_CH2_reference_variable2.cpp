#include <iostream>
using namespace std;


int main(void){
    int num=10;
    int &ref1 = num;
    // int &ref2 = 100;
    int &ref3 = ref1;
    // int &ref4 = ref2;

    num = num*3;

    cout << "val1 = " << num << endl;
    cout << "val2 = " << ref1 << endl;
    cout << "val3 = " << ref3 << endl;

    return 0;
}