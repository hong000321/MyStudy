#include <iostream>

using namespace std;

class SoSimple{
private:
	static int simObjCnt;
public:
    SoSimple(){
		simObjCnt++;
		cout << this << " : "<< simObjCnt << "번째 생성" << endl;
	}
};

int SoSimple::simObjCnt = 0;

int main(void){

    SoSimple a;
    SoSimple b;
    SoSimple c;

    return 0;
}