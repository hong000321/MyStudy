#include <iostream>
#include <string.h>
using namespace std;


template <typename T>
T Max(T a, T b){
    return a > b ? a : b ;
}


template <>
char * Max(char* a, char* b){
    cout << " char Max<char*>(char* a, char* b)"<<endl;
    return strcmp(a,b)>0 ? a:b;
}

template <>
const char * Max(const char* a, const char* b){
    cout << " const char Max<const char*>(const char* a, const char* b)"<<endl;
    return strcmp(a,b)>0 ? a:b;
}


int main(void){
    cout << Max(11,15)      << endl;
    cout << Max('T','Q')      << endl;
    cout << Max(3.5,3.7)      << endl;
    cout << Max("Simple","Best")      << endl;
    char str1[] = "Simple";
    char str2[] = "best";
    cout << Max(str1,str2)      << endl;
    return 0;
}