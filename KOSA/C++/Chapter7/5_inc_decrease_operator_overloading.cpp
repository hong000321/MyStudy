#include <iostream>

using namespace std;


class Point{
private:
    int xpos, ypos;
public:
    Point (int x=0, int y=0) : xpos(x), ypos(y){}
    void ShowPosition() const{
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }
    Point& operator++(){  // 전위증감은 인자가 없음
        xpos+=1;
        ypos+=1;
        return *this;
    }
    friend Point& operator--(Point &ref); // 전역 설정으로 입력이 하나는 무조건 있어야함.
    
    Point& operator--(int){  // 후위 즘감은 인자가 1개 들어감
        xpos-=1;
        ypos-=1;
        return *this;
    }
    friend const Point& operator++(Point &ref, int); // 전역 설정으로 입력이 두개는 무조건 있어야함.
};

Point& operator--(Point &ref){ 
    ref.xpos-=1;
    ref.ypos-=1;
    return ref;
}

const Point& operator++(Point &ref, int){ 
    const Point retobj(ref);
    ref.xpos+=1;
    ref.ypos+=1;
    return retobj;
}



int main(void){
    Point pos(1,2);
    
    pos.ShowPosition();
    ++pos;
    
    pos.ShowPosition();
    --pos;
    
    pos.ShowPosition();
    pos++;
    
    pos.ShowPosition();
    pos--;
    
    
    
    pos.ShowPosition();

    return 0;
}