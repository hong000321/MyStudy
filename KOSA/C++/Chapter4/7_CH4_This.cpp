#include <iostream>
using namespace std;


class Chulsoo{
private:
    int age;
public:
    Chulsoo(int age){
        this->age = age;
        cout << " Chulsoo::Chulsoo(age) 생성자 완료" << endl;
    }
    void setAge(int age){
        this->age = age;
    }
    void introduce(){
        cout << "철수의 나이는 " << age << "세 입니다." <<endl;
    }
    Chulsoo* returnThisPointer(){
        return this;
    }
    Chulsoo returnThis(){
        return *this;
    }
    Chulsoo& returnThisRef(){
        return *this;
    }
};


int main(void){
    Chulsoo chulsoo1(32);
    cout << "chulsoo1 객체 introduce" << endl;
    chulsoo1.introduce();
    chulsoo1.setAge(50);
    chulsoo1.introduce();

    Chulsoo chulsoo2(16);
    cout << "chulsooPointer introduce" << endl;
    chulsoo2.returnThisPointer()->introduce();
    chulsoo2.returnThisPointer()->setAge(24);
    chulsoo2.returnThisPointer()->introduce();

    Chulsoo chulsoo3(53);
    cout << "chulsooPointer introduce" << endl;
    chulsoo3.returnThis().introduce();
    chulsoo3.returnThis().setAge(33);
    chulsoo3.returnThis().introduce();

    Chulsoo chulsoo4(25);
    cout << "chulsooPointer introduce" << endl;
    chulsoo4.returnThisRef().introduce();
    chulsoo4.returnThisRef().setAge(44);
    chulsoo4.returnThisRef().introduce();

    return 0;
}