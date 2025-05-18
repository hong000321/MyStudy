/*
1이상 100 이하의 정수 N을 입력받아 재귀함수를 이용해 1부터 N까지 출력하고 
그 다음줄에 N부터 1까지 출력하는 프로그램을 작성하시오.
*/

#include<stdio.h>

void func(int x, int dir){
    if(x<1){
        return;
    }
    if(dir == 1){
        printf("%d ",x);    
    }
    func(--x,dir);
    if(dir == 0){
        printf("%d ",x+1);
    }
    
}

int main(){
    int N;
    scanf("%d", &N);

    func(N,0);
    func(N,1);

    return 0;
}