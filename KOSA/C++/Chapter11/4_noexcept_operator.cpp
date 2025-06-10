#include <iostream>
using namespace std;

void handler(){
    cout << "in handler" << endl;
}


void f1(void) noexcept(false){
    cout << "About to throw 1" <<endl;
    if(1)
        throw 1;
}

void f2(void) noexcept(true){  // noexcept 는 예외를 허용할지 말지를 결정함. 따라서 활성화 하고 throw를 던지면 프로그램이 죽음
                            // 이때 noexcept(0) 를 하게 되면 예외 허용이기 때문에 실행가능
    try{
        f1();
    }
    catch(...){
        handler();
        throw;
    }
}

int main(void){
    // f1();
    try{
        f2();
    }
    catch(...){
        cout << "Caught exception from f2" << endl;
    }
    return 0;
}