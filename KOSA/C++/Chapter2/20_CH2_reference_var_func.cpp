#include <iostream>
using namespace std;

void foo(int &ref)
{
    ref++;
}

int main(void){
    int x=10;
    foo(x);
    cout << "x = " << x << endl;

    return 0;
}