#include <iostream>
using namespace std;

#define NAME_LEN 20
#define SEX_LEN 10
#define JOB_LEN 20
#define CHARACTER_LEN 20


struct Chulsoo{
    char name[NAME_LEN];
    char sex[SEX_LEN];
    char job[JOB_LEN];
    char character[CHARACTER_LEN];
    int age;
    void introduce(){
        cout << "이름 : " << name << endl;
        cout << "성별 : " << sex << endl;
        cout << "직업 : " << job << endl;
        cout << "캐릭터 : " << character << endl;
        cout << "나이 : " << age << endl;
    }
    void eat(char* food){
        cout << "철수는 " << food << "먹는다." << endl;
    }
    void sleep();
    void drive(char* destination){
        cout << destination << "으로 운전해라" << endl;
    }
};


int main(void){
    Chulsoo chulsoo = { "철수" ,"남성", "작가" , "diligent", 32}; //true
    chulsoo.introduce();
    chulsoo.drive((char*)"레스토랑");
    chulsoo.eat((char*)"스테이크");

    return 0;
}