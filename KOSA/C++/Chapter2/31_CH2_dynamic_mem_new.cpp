#include <iostream>
using namespace std;

char* NumberToString(int n){
    char *tmp = new char[20];  // 포인터를 리턴하기 때문에 동적할당을 받아서 전달해야함. 
                               // 그냥 배열를 쓴다면 이미 해제된 stack영역을 참조하기 때문에 쓰레기 값이감넘어감
    sprintf(tmp,"%d",n);
    return tmp;
}

int main(void){
    char *str = NumberToString(12342);

    cout << str << endl;
    delete [] str;



    return 0;
}