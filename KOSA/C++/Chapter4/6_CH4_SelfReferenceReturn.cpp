#include <iostream>
using namespace std;

class SelfRef{
private:
    int num;

public:
    SelfRef(int n) : num(n){
        cout<<"객체생성"<<endl;
    }
    SelfRef& Adder(int n){
        num+=n;
        return *this; //self reference
    }
    SelfRef& ShowTwoNumber(){
        cout<<num<<endl;
        return *this; //self reference
    }
};


int main(void){
    SelfRef obj(3);
    SelfRef &ref = obj.Adder(2);
    obj.ShowTwoNumber();
    ref.ShowTwoNumber();
    ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber(); // self reference 를 통해 cout의 스트림 처럼 체인을 이루어 실행 가능
    return 0;
}