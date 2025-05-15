#include <iostream>
using namespace std;

void print(int &x){
    cout << " printf(int &x):" << x << endl;
}

void print(const int &x){
    cout << " printf(const int &x):" << x <<endl;
}

void print(int &&x){
    cout << " printf(int &&x):" << x <<endl;
}

int main(){
    int a= 10;
    int &x1 = a;
    const int &x2 = 10;
    int &&x3 = 10;
    int &&x4 = std::move(a);

    print(a);
    print(x1);
    print(x2);
    print(x3);
    print(x4);
    print(a);
    print(12);
    return 0;
}
