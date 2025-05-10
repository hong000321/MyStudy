#include <iostream>

using namespace std;

void SwapInPtr(int *x, int*y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void SwapInRef(int &x, int &y){
    int tmp = x;
    x = y;
    y = tmp;
}

int main(void){
    int a, b;
    cout << "두 수를 입력하세요: ";
    cin >> a >> b;
    cout << "Swap 호출 전의 a = " << a << ", b = " << b << endl;
    SwapInPtr(&a,&b);
    cout << "Swap Ptr 호출 후의 a = " << a << ", b = " << b << endl;
    SwapInRef(a, b);
    cout << "Swap 호출 후의 a = " << a << ", b = " << b << endl;

    return 0;
}