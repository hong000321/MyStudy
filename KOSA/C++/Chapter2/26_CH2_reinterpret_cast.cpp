#include <iostream>

using namespace std;


int main(void){
    int num = 0x040704;
    char *ptr = reinterpret_cast<char *>(&num);
    cout << static_cast<int>(*(ptr+1)) << endl;

    return 0;
}