#include <iostream>
using namespace std;

class SoSimple{
private:
    int num1;
    int num2;
public:
    SoSimple(int n1, int n2) :  num1(n1), num2(n2){}
    /*아래 내용이 자동 삽입
    SoSimple(const SoSimple &copy) : num1(copy.num1), num2(copy.num2){}
    */
    int getNum(int i){
        return (i==1)?this->num1:this->num2;
    }
};

int main(void){
    SoSimple sp1(3,4);

    printf("%d %d" , sp1.getNum(1), sp1.getNum(2));
    return 0;
}
