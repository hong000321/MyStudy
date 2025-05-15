#ifndef _POINT_H_
#define _POINT_H_

class Point{
public:
    Point() : x(0), y(0){
        // empty
    }
    Point(const int x, const int y) : x(x), y(y){
        // empty
    }
    friend Point operator+(const Point& b, const Point& b);
    friend Point operator-(const Point& b, const Point& b);
private:
    int x;
    int y;
};

Point operator+(const Point& a, const Point& b){
    Point tmp;
    tmp.x = a.x + b.x;
    tmp.y = a.y + b.y;
    return tmp;
}
Point operator-(const Point& a, const Point& b){
    Point tmp;
    tmp.x = a.x - b.x;
    tmp.y = a.y - b.y;
    return tmp;
}


#endif //_POINT_H_