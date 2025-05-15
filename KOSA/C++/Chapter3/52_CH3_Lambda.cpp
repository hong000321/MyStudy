#include <iostream>

int main(void){
    [](int x, int y){ std::cout << "합은 " << x+y; }(2,3);

    return 0;
}