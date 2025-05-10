#include <iostream>
int BoxVolume(int length=1,int width = 1, int height=1); // DefaultValue는 선언 하는 시점에 한번만 가능함.
    //선언부 and 구현부 -> 선언부에 기본값 선언, 구현부에서는 기본값 설정하면 컴파일 에러남.
    //선언+구현부 -> 함수 정의 하면서 함께

int main(void){
    std::cout << "[3,3,3]:" << BoxVolume(3,3,3) << std::endl;
    std::cout << "[5,5,d]:" << BoxVolume(5,5) << std::endl;
    std::cout << "[7,D,D]:" << BoxVolume(7) << std::endl;
    std::cout << "[D,D,D]:" << BoxVolume() << std::endl;
    return 0;
}


int BoxVolume(int length, int width, int height)
{
    return length*width*height;
}