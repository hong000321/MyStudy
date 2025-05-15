#include <iostream>
#include <memory>
using namespace std;

int main(void){
    unique_ptr<int> ptr01(new int(5));

    auto ptr02  = move(ptr01);

    // 대입 연산자를 이용한 복사는 오류를 발생시킴.
    //unique_ptr<int> ptr03 = ptr01;

    ptr02.reset();
    ptr01.reset();
    
    return 0;
}

