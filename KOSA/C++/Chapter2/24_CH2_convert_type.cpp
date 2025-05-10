#include <iostream>

using namespace std;

int main(){
    int i;
    int arr[10];
    for(i=0 ; i<10 ; i++){
        arr[i] = i*2;
    }
    int *ptr = arr;
    cout << arr[4] << endl;
    cout << *(ptr+4) << endl;
    return 0;
}