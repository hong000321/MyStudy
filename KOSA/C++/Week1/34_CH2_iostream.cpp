#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main(){
    string str = "파일에씁니다.";
    ofstream ofs("file.txt");
    ofs << str;
    ofs.close();
    ifstream ifs("file.txt");
    ifs >> str;
    cout << str << endl;
    ifs.close();    

    return 0;
}