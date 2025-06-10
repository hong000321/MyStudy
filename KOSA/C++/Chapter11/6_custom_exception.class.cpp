#include <iostream>
using namespace std;

class MyException{
    int myValue;
    int myResult;
    enum {
        EX_INPUT_IS_SMALL,
        EX_INPUT_IS_BIG,
        EX_INPUT_IS_NOT_7MULTI,
    };
public:
    MyException(int value){
        myValue = value;
        if(myValue<10)
            myResult = EX_INPUT_IS_SMALL;
        else if(myValue>20)
            myResult = EX_INPUT_IS_BIG;
        else if (myValue %7 !=0)
            myResult = EX_INPUT_IS_NOT_7MULTI;
    }
    void exceptionResult(){
        if(myResult == EX_INPUT_IS_SMALL)
            cout << "10이상의 값을 입력하세요" << endl;
        else if(myResult == EX_INPUT_IS_BIG)
            cout << "20이하의 값을 입력하세요" << endl;
        else if (myResult == EX_INPUT_IS_NOT_7MULTI)
            cout << "7의 배수 값을 입력하세요" << endl;
    }
};


int main(){
    int value;
    try{
        cout << "10과 20 사이의 7의 배수를 입력하세요:" ;
        cin >> value;
        if(value <10 | value>20 | value%7!=0){
            throw MyException(value);
        }
        cout << "정답 !! 10과 20사이의 7의 배수는 " << value << "입니다"<< endl;

    }
    catch(MyException &e)
    {
        e.exceptionResult();
    }
    return 0;
}
