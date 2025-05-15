/**
 * ()연산자의 오버로딩
 * 객체를 함수처럼 사용할 수 있게 해줌
 * 객체 adder 를 adder(3,4); 와 같은 형태로 사용 할 수 있음.
 */
#include <iostream>
using namespace std;

class Point{
private:
    int x;
    int y;
public:
    Point(int x, int y){
        this->x = x;
        this->y = y;
    }
    Point(){
        this->x = 0;
        this->y = 0;
    }
    friend Point operator+(const Point& ref1, const Point& ref2);
    // operator std::string (){
    //     return "[" + std::to_string(x) + "," + std::to_string(x) + "]";
    // }
    friend ostream& operator<<(ostream& os, const Point& pos); 
};

Point operator+(const Point& ref1, const Point& ref2){
    Point tmp;
    tmp.x = ref1.x + ref2.x;
    tmp.y = ref1.y + ref2.y;
    return tmp;
}

ostream& operator<<(ostream& os, const Point& pos)
{
  os<<'['<<pos.x<<", "<<pos.y<<']'<<endl;
  return os;
}

class Adder{
public:
    int operator()(const int& n1, const int & n2){
        return n1+n2;
    }
    double operator()(const double& n1, const double & n2){
        return n1+n2;
    }
    Point operator()(const Point& n1, const Point & n2){
        return n1+n2;
    }
    
};

int main(void){
    Adder adder;
    cout<<adder(1, 3) <<endl;
    cout<<adder(1.5, 3.7)<<endl;
    cout<<adder(Point(3,4), Point(7,9));

    return 0;
}