#include <iostream>

using namespace std;

template <typename T>
T const add_hdo(T const& a, T const& b){
    return a+b;
}

int main(){
    double i= 5.1;
    double j = 10.2;
    int a = 5;
    int b = 10;

    // cout << i << " + " << j << " =" << add<double>(i,j) << endl;
    // cout << a << " + " << b << " = " << add<int>(a,b) << endl;

    cout << i << " + " << j << " =" << add_hdo(i,j) << endl;
    cout << a << " + " << b << " = " << add_hdo(a,b) << endl;
    return 0;
}