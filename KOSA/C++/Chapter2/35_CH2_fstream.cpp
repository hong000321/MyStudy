#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    fstream fs;
    fs.open("test.txt", ios::out);
    if(fs.fail())
        return 0;
    
    fs << "keyboard" << endl;
    fs << "monitor" << endl;

    fs.close();

    fs.open("test.txt", ios::out | ios::trunc);
    fs << "desk" << endl;
    fs.close();
    fs. open("test.txt", ios::in);
    string temp;

    while(fs >> temp, !fs.eof()){
        cout << temp << endl;
    }
    fs.close();

    return 0;

}