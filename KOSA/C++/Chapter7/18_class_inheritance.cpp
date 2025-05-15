#include <iostream>
#include <string.h>
using namespace std;

class Person{
private:
    int age;
    char name[50];
public:
    Person(int myage, char * myname) : age(myage){
        strcpy(name, myname);
    }
    void WhatYoutName() const{
        cout<< "My name is " <<name<<endl;
    }
    void HowOldAreYou() const{
        cout<<"I'm " << age<< " years old" << endl;
    }
};

class UnivStudent : public Person{
private:
    char major[50];
public:
    UnivStudent(char * myname, int myage, char * mymajor) : Person(myage, myname){
        strcpy(major, mymajor);
    }
    void WhoAreYou() const{
        WhatYoutName();
        HowOldAreYou();
        cout<< "My major is " << major << endl << endl;
    }
};

int main(void){
    UnivStudent st("dae o", 22, "aero");
    st.WhoAreYou();
    return 0;
}