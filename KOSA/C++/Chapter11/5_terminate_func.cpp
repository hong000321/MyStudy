#include <iostream>
#include <exception>

using namespace std;

void MyErrorHandler(){
    cout << "처리되지 않은 예외가 발생했습니다." << endl;
    exit(-1);
}

int main(void){
    set_terminate(MyErrorHandler);
    try{
        char test[] = "test";
        throw (char* const)test;
    }
    catch(char* const ex) {
        // 이 catch 절은 정수형 예외를 처리할 수 없음.
        cout << ex << endl;
    }
    return 0;
}