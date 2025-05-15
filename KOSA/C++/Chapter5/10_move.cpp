#include <iostream>

using namespace std;

class MyArray{
private:
    int num;
public:
    MyArray(int n){
        cout << "생성자 호출 1" << endl;
        num = n;
    }
    MyArray(const MyArray& copy){
        cout << "복사 생성자 호출 2" << endl;
        num = copy.num;
    }
    MyArray(MyArray&& move){
        cout << "이동 생성자 호출 3" << endl;
        num = move.num;
        move.num = 0;
    }
    MyArray operator = (MyArray&& move){
        cout << "이동 대입 연산자 호출 4" << endl;
        swap(num, move.num);
        return *this;
    }
    int getNum(){
        return num;
    }
};

MyArray CreateMyArray(){
    return MyArray(100);
}

int main(){
    MyArray ar1(10);
    MyArray ar2(ar1);
    // MyArray ar4 = ar1;

    cout << "ar1.getNum: " << ar1.getNum() << endl;
    cout << "ar2.getNum: " << ar2.getNum() << endl;
    cout << endl;

    //ar2 = MyArray(100);
    ar2 = CreateMyArray();
    cout << "ar1.getNum: " << ar1.getNum() << endl;
    cout << "ar2.getNum: " << ar2.getNum() << endl;
    cout << endl;

    MyArray ar3(std::move(ar1));
    cout << "ar1.getNum: " << ar1.getNum() << endl;
    cout << "ar2.getNum: " << ar2.getNum() << endl;
    cout << endl;

    return 0;
}