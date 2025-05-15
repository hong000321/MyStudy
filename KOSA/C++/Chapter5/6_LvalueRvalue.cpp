#include <iostream>
using namespace std;

// R-value를 리턴
int Add(int x, int y){
    return x+y;
}

// L-value를 리턴
int & inc(int &x){
    return ++x;
}

int main(){
    int x = 5;      // x는 l-value, 5는 r-value
    int y = x*5;    // y는 l-value, x*5는 r-value
    ++x = 7;        // ++x는 l-value, 7은 r-value
}