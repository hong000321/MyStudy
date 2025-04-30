/*
10이하의 정수 N을 입력 받아서 재귀함수로 1부터 N까지 출력하는 프로그램이 있다.

함수 func(int x)을 작성하여 프로그램을 완성시키자.

*/

// 제출해야 하는 부분 시작
#include<stdio.h>
void func(int x){
    if(x<1){
        return;
    }
    func(--x);
    printf("%d ",x+1);
}

// 제출해야 하는 부분 끝

int main(){
    int N;
    scanf("%d", &N);

    func(N);

    return 0;
}