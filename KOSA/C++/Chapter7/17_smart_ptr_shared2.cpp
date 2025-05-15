#include <iostream>
#include <memory>
using namespace std;

class Chulsoo{
private:
    int age;
public:
    Chulsoo(int age) : age(age) {
        cout <<  "Chulsoo::Chulsoo(age) 생성자 완료" << endl;
    }
    Chulsoo() {
        cout <<  "Chulsoo::Chulsoo() 생성자 완료" << endl;
    }
    ~Chulsoo() {
        cout <<  "Chulsoo::~Chulsoo() 소멸자 완료" << endl;
    }
    void introduce(){
        cout << "철수 나이: " <<age << endl;
    }
};


int main(void){
    shared_ptr<Chulsoo> chulsooSmptr1(new Chulsoo(32));
    chulsooSmptr1->introduce();
    cout << "unique_ptr<Chulsoo> 타입간 복사 생성자 호출 후 " << endl;
    shared_ptr<Chulsoo> chulsooSmptr2 = chulsooSmptr1;
    cout << chulsooSmptr1.use_count() << endl;
    chulsooSmptr1->introduce();
    chulsooSmptr2->introduce();
    
    return 0;
}

