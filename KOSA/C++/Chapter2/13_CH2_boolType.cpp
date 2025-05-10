#include <iostream>
using namespace std;

int main(){
    bool a=true;

    cout << "a= " << a << endl;
    a=false;
    cout << "a= " << a << endl;
    a=-98;
    cout << "a= " << a << endl;
    a=0;
    cout << "a= " << a << endl;

// 결과 값은 1010 으로 나오지만 컴파일러에 따라서 결과가 달라질 수 있으니
// 0이냐 1이냐가 아닌 
// 0이냐 0이 아니냐로 구분을 해야한다.
    return 0;
}