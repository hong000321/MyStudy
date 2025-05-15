#include <iostream>
using namespace std;

class Chulsoo{
private:
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
public:
    Chulsoo(const char* i_name, const char* i_sex, const char* i_job, const char* i_char, int i_age){
        sprintf(name,"%s",i_name);
        sprintf(sex,"%s",i_sex);
        sprintf(job,"%s",i_job);
        sprintf(character,"%s",i_char);
        age = i_age;
    }
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
    // Chulsoo chulsoo = {"철수" ,"남성", "작가" , "diligent", 32}; // private은 리스트 입력이 불가능 함.
    Chulsoo chulsoo("철수" ,"남성", "작가" , "diligent", 32);
    chulsoo.introduce();
    chulsoo.drive("레스토랑");
    chulsoo.eat("스테이크");

    return 0;
}