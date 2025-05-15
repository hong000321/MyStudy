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
    // operator std::string (){
    //     return "[" + std::to_string(x) + "," + std::to_string(x) + "]";
    // }
    friend ostream& operator<<(ostream& os, const Point& pos); 
};



ostream& operator<<(ostream& os, const Point& pos)
{
  os<<'['<<pos.x<<", "<<pos.y<<']'<<endl;
  return os;
}



class BoundCheckPointArray{
private:
    Point * arr;
    int arrlen;
public:
    BoundCheckPointArray(int len) :arrlen(len){
        arr=new Point[len];
    }
    Point& operator[] (int idx){
        if(idx<0 || idx>=arrlen){
            cout<<"Array index out of bound exeption" <<endl;
            exit(1);
        }
        return arr[idx];
    }
    Point operator[] (int idx) const{
        if(idx<0 || idx>=arrlen){
            cout <<"Array index out of bound exception" << endl;
            exit(1);
        }
        return arr[idx];
    }
    int GetArrlen() const { return arrlen;}
    ~BoundCheckPointArray() {delete []arr;}
};

int main(void){
    BoundCheckPointArray arr(3);
    arr[0] = Point(3,4);
    arr[1] = Point(3,4);
    arr[2] = Point(3,4);
    for(int i=0; i<arr.GetArrlen(); i++){
        cout << arr[i];
    }
    return 0;
}