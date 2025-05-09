#include <iostream>

using namespace std;

int f(){
    return 20+30;
}

int main(void){
    double d=1.414;
    decltype(f()) decVar;  // 초기값 없이 선언 가능
    decltype(f()) decVar1 = d;
    decltype(d) decVar2 = decVar1;
    decltype((d)) decVar3 = decVar2; //  ()사용 시 refernce 변수로 적용
    decVar2 = 3.141592;

    cout << decVar << "  " << &decVar << endl;
    cout << decVar1 << "  " << &decVar1 << endl;
    cout << decVar2 << "  " << &decVar2 << endl;
    cout << decVar3 << "  " << &decVar3 << endl;

    return 0;
}