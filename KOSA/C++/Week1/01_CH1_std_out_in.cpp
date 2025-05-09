#include <iostream>

int main()
{
    int val1;
    // std namespace에 ::(범위지정자 or 스코프 연산자자)를 사용하여 접근하여 cout에 스트림으로 
    std::cout << "Hello World!" << std::endl;  // <<(출력) , >>(입력) 스트림 연산자
    std::cin >> val1;  // >> 로 출력
    std::cout << "input num : " << val1 << std::endl;
    return 0;
}