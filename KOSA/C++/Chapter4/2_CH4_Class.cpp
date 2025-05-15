#include <iostream>
using namespace std;

class Chulsoo{
public:
    enum{
        NAME_LEN = 20,
        SEX_LEN = 10,
        JOB_LEN = 20,
        CHARACTER_LEN = 20
    };
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
    void eat(const char* food){
        cout << "철수는 " << food << "먹는다." << endl;
    }
    void sleep();
    void drive(const char* destination){
        cout << destination << "으로 운전해라" << endl;
    }
};


int main(void){
    Chulsoo chulsoo = { "철수" ,"남성", "작가" , "diligent", 32}; // public 일때만 리스트 형태로 입력 가능, private은 불가능 함.
    chulsoo.introduce();
    chulsoo.drive("레스토랑");
    chulsoo.eat("스테이크");

    return 0;
}