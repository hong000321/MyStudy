#include <iostream>
using namespace std;

class Chulsoo;


struct Youngsoo{
private:
    int age;
public:
    Youngsoo(int age) : age(age){
        cout << "Youngsoo::Youngsoo(age) 생성자 완료" << endl;
    }
    void introduce(){
        cout << "영수 나이: " << age << endl;
    }
    friend class Younghee;
};

class Younghee{
private:
    int age;
public:
    Younghee(int age) : age(age){
        cout << "Younghee::Younghee(age) 생성자 완료" << endl;
    }
    void introduce(){
        cout << "영희 나이: " << age << endl;
    }
    void whoIsOlder(const Chulsoo & chulsooObj);
    void whoIsOlder2(const Youngsoo & younsooObj);
};

class Chulsoo{
private:
    int age;
public:
    Chulsoo(int age) : age(age){
        cout << "Chulsoo::Chulsoo(age) 생성자 완료" << endl;
    }
    void introduce(){
        cout << "철수 나이: " << age << endl;
    }
    friend class Younghee;
};

void Younghee::whoIsOlder(const Chulsoo & chulsooObj){
    cout << "영희는 철수보다" << ((age > chulsooObj.age)?"나이가 많다":"나이가 같거나 적다") << endl;
}

void Younghee::whoIsOlder2(const Youngsoo & youngsooObj){
    cout << "영희는 영수보다" << ((age > youngsooObj.age)?"나이가 많다":"나이가 같거나 적다") << endl;
}



int main(void){
    Chulsoo chulsoo1(32);
    chulsoo1.introduce();

    Younghee younghee1(35);
    younghee1.introduce();

    Youngsoo youngsoo1(37);
    youngsoo1.introduce();

    younghee1.whoIsOlder(chulsoo1);
    younghee1.whoIsOlder2(youngsoo1);
    return 0;
}