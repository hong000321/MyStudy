#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


int main(void){
    int arr[10] = {97, 44, 23, 55,61,12,3,75,27,84};
    cout << "정렬된 배열 : ";
    sort(arr,arr+9);
    for(int i=0; i<10; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";

    vector<string> strings;
    string s;

    cout << "문자열을 입력하세요 : ";
    while(cin>>s)
        strings.push_back(s);
    
    sort(strings.begin(), strings.end());
    cout << "정렬된 문자열 : ";
    for(auto it = strings.begin(); it!=strings.end(); it++)
        cout << *it << " ";
    cout << "\n";
    return 0;
}



