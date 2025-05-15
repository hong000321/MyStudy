#include <iostream>

using namespace std;

class AAA{
private:
	static int g_a;
public:
	AAA(){
		g_a++;
		cout << this << " : "<< g_a << "번째 생성" << endl;
	}
};

int AAA::g_a = 0;

int main(void){

    AAA a;
    AAA b;
    AAA c;


    return 0;
}