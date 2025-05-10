#include <iostream>
using namespace std;

class Chulsoo{
public:
    int Eat(int Steaknum = 20000, int WaterNum = 1000, int CoffeeNum = 5000);
};




int main(void){
    Chulsoo chulsoo;

    chulsoo.Eat();
    chulsoo.Eat(30000);
    chulsoo.Eat(1500);
    chulsoo.Eat(20000,1500);

    return 0;
}

int Chulsoo::Eat(int SteakNum, int WaterNum, int CoffeeNum){
    cout << "철수는 " << SteakNum << "원 짜리 스테이크를 먹고. ";
    cout << WaterNum << "원 짜리 물을 먹고, " ;
    cout << CoffeeNum << "원 짜리 커피를 먹는다." << endl;
    return SteakNum;
}