#include <iostream>
#include <string.h>

using namespace std;

class Person{
private:
    char *name;
    int age;
public:
    Person(const Person& source){ // new를 통한 동적할당을 위해서는 복사 생성자와 
        // delete [] name;
        int len=strlen(source.name)+1;
        name = new char[len];
        strcpy(name, source.name);
        this->age = source.age;
    }
    Person(char * myname, int myage){
        int len = strlen(myname)+1;
        name = new char[len];
        strcpy(name, myname);
        age=myage;
    }
    void ShowPersonInfo() const{
        cout << "이름: " << name << endl;
        cout << "나이: " << age<< endl;
        // printf("주소: %p\n\n",this->name);
        cout << "주소: " << &this->name << endl << endl;
    }
    Person& operator=(const Person& source){
        delete [] name;
        int len=strlen(source.name)+1;
        name = new char[len];
        strcpy(name, source.name);
        this->age = source.age;
        return *this;
    }
    ~Person(){
        delete []name;
        cout << "called destructor!" << endl;
    }
};

int main(void){
    Person man1("Lee dong woo" ,29);
    Person man2("Yoon ji yul" ,22);
    Person man3("YoungJin Suh" ,33);
    Person *man4 = new Person("yong" , 22);
    man2=man1;
    man3=man2;
    man1.ShowPersonInfo();
    man2.ShowPersonInfo();
    man3.ShowPersonInfo();
    return 0;
}