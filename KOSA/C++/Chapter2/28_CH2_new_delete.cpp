#include <iostream>
using namespace std;

int foo(int a){
    return a+2;
}

float bar(int a){
    return a+3;
}

int main(void){
    int *p = NULL;
    p = nullptr;
    p = new int(4.2);
    delete p;
    //p = new int{4.2}; 
    p = new int{bar(4)};   // 대괄호는 개수 , 소괄호는 값, 중괄호는? 형태에 엄격하게 체크 후 에러 반환
    if(p == NULL){
        cout << "동적 메모리 할당 실패\n" << endl;
        return 1;
    }
    
    cout << "입력된 정수는 " << p[0] << "\n";

    cout << "정수를 입력하세요:";
    cin >> *p;
    cout << "입력된 정수는 " << p[0] << "\n";

    delete p;
    p=NULL;  // 안하면 프로그램이 죽을 위험이 있음.
    return 0;
}