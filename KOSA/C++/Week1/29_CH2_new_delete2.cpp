#include <iostream>

using namespace std;

int main(void){
    int num;
    cin >> num;
    int *data = new int[num];
    for(int i=0; i<num; i++)
        cin>>data[i];
    cout << data[num-1] << endl;

    delete data;
    cout << data[num-1] << endl;
    return 0;
}