#include <iostream>
using namespace std;

int main(){
    // const char *cp;
    // char *q = static_cast<char*>(cp);
    // const_cast<string>(cp);

    const char* str = "Hello";
    char * str2 = const_cast<char*>(str); //  const 성향 제거!
    cout << str2 << endl;

    char *str3 = const_cast<char*>(str);  //  const 성향 제거!
    str3[2] = 'a';
    cout << str3 << endl;
    return 0;
} 