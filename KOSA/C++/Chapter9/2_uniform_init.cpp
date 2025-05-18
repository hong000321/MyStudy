#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Person{
private:
    int age;
    string name;
public:
    Person(const int a, const string& n): age(a), name(n){}
    int getAge() {return age;}
    string getName() {return name;}
};

int main(int argc, char **argv){
    Person p1{20, "Tom"};
    Person p2{19, "Jane"};

    vector<Person> vec{
        {21,"Smith"}, {39, "John"}, {23, "Mary"}, {45, "Ted"}
    };
    for_each(vec.begin(), vec.end(), [](Person p){
        cout << p.getAge() <<"," << p.getName() <<endl;
    });
    return 0;
}


