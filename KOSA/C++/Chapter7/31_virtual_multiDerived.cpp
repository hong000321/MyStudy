#include <iostream>
using namespace std;

class Person{
public:
    Person(){
        cout << "Person::Person() 생성자 호출" << endl;
    }
    void sleep(){
        cout << "잔다" << endl;
    }
    ~Person(){
        cout << "Person::~Person() 소멸자 홀출" << endl;
    }
    virtual void write() = 0;
};

class Chulsoo : public virtual Person{
public:
    Chulsoo() : Person(){
        cout << "Chulsoo::Chulsoo() 생성자 호출" << endl;
    }
    ~Chulsoo(){
        cout << "Chulsoo::~Chulsoo() 소멸자 호출" << endl;
    }
    void write(){
        cout << "책을 잘 쓴다" << endl;
    }
};

class Younghee : public virtual Person{
public:
    Younghee() : Person(){
        cout << "Younghee::Younghee() 생성자 호출" << endl;
    }
    ~Younghee(){
        cout << "Younghee::~Younghee() 소멸자 호출" << endl;
    }
    void write(){
        cout << "책을 못 쓴다" << endl;
    }
};
class Youngchul : public Chulsoo ,public Younghee{
public:
    Youngchul() : Chulsoo(), Younghee(){
        cout << "Youngchul::Youngchul() 생성자 호출" << endl;
    }
    ~Youngchul(){
        cout << "Youngchul::~Youngchul() 소멸자 호출" <<endl;
    }
    void write() {
        // write();
        Chulsoo::write();
    }

};

int main(void){
    Youngchul youngchul;
    youngchul.write();
    youngchul.sleep();
    return 0;
}

