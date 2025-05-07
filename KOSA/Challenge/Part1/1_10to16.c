#include <stdio.h>  // scanf, printf를 위한 헤더파일 추가

int main(void){
    int decimal = 0;
    printf("10진수 값 입력: ");
    scanf("%d",&decimal);  // 10진수 값을 표준입력에서 10진수 형태로 가져옴
    printf("10진수: %d 는 16진수 :%x \n",decimal,decimal); // 10진수 출력은 %d , 16진수 출력은 %x 

    return 0;
}