#include <iostream>
using namespace std;

class Chulsoo{
public:
    int count; // 철수가 스테이크를 먹는 횟수
};

int main(void){
    Chulsoo chulsoo;
    chulsoo.count = 0;
    cout << [=](int steakWeight)mutable->char{cout << "eatLambda()::철수는 " << ++chulsoo.count << "번째 " << steakWeight << "g 짜리 스테이크를 먹는다" <<endl; \
                                        return steakWeight;}(67) << endl;
    cout << [=](int steakWeight)mutable->int{cout << "eatLambda()::철수는 " << ++chulsoo.count << "번째 " << steakWeight << "g 짜리 스테이크를 먹는다" <<endl; \
                                        return steakWeight;}(67) << endl;
    cout << [=](int steakWeight)mutable{cout << "eatLambda()::철수는 " << ++chulsoo.count << "번째 " << steakWeight << "g 짜리 스테이크를 먹는다" <<endl; \
                                        return steakWeight;}(67) << endl;

    cout << chulsoo.count;
    return 0;
}

