#include <iostream>
#include <exception>
using namespace std;


int main(){
    int num=0;
    int **p = new int*[10000];
    try{
        while(1){
            num++;
            cout<<num<<"번째 할당 시도"<<endl;
            p[num] = new int[100000000]; // 400MB 씩 280번 
            *p[num] = 1; // 진짜 물리 메모리 할당
        }
    }catch(bad_alloc &bad){
        cout<<bad.what()<<endl;
        cout<<"더 이상 할당 불가!"<<endl;
    }
    return 0;
}