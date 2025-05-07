#include <stdio.h>

void PrintConvTime(int sec){
    int h,m,s;
    h = sec/(60*60); // 변환된 시(h)는 3600초로 나눈 몫과 같음
    m = (sec-h*60*60)/(60);  // 변환된 분(m)은 시(h)의 초를 뺀 시간에서 60으로 나눈 값과 같은
    s = sec%60;  // 변환된 초는 전체 초의 60의 나머지와 같음
    printf("[h:%d, m:%d, s:%d]",h,m,s);
}

int main(void){
    int sec = 0;

    printf("초(second) 입력: ");
    scanf("%d",&sec);

    PrintConvTime(sec);

    return 0;
}