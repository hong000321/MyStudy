#include <iostream>
#include <memory>
using namespace std;


int main(void){
    shared_ptr<int> ptr01(new int(5));
    cout << ptr01.use_count() << endl;
    auto ptr02(ptr01);
    cout << ptr01.use_count() << endl;
    auto ptr03 = ptr01;
    cout << ptr01.use_count() << endl;

    ptr02.reset();
    cout << ptr01.use_count() << endl;
    ptr03.reset();
    cout << ptr01.use_count() << endl;

    return 0;
}

