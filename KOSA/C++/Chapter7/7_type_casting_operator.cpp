#include <iostream>
using namespace std;


class Number{
private:
    int num;
public:
    Number(int n=0) : num(n){
        cout << "Number(int n=0) " << endl;
    }
    Number& operator=(const Number& ref){
        cout << "operator=()" << endl;
        num=ref.num;
        return *this;
    }
    operator int (){
        cout << "int type casting operator" << endl;
        return num;
    }
    // Number& operator+(const Number& n){
    //     cout << "+ operator" << endl;
    //     this->num+=n.num;
    //     return *this;
    // }
    void ShowNumber() { cout << num << endl;}


};


int main(void){
    Number num1;
    cout << endl;

    num1=30;
    cout << endl;

    Number num2 = num1+20;
    cout << endl;

    Number *num3 = new Number(3);

    num2.ShowNumber();
    cout << endl;

    cout << num2 << endl;
    return 0;
}