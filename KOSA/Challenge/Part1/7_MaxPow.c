#include <stdio.h>

int GetMaxPow(int n){
    int k=0; // 2씩 나누면서 k를 1씩 증가 시키기 때문에 무조건 초기화는 0으로 되어있어야함.
    while(1){
        if(n<2){ // n이 2보다 작으면 k값이 최대이기 때문에 while을 종료
            break;
        }
        n/=2;  // n이 2보다 크기 때문에 2로 나눈 값을 n에 다시 저장
        k++;   // 2로 나누어서 k값이 하나 늘어남.
    }
    return k;
}

int main(void){
    int n,k;
    printf("상수 n 입력: ");
    scanf("%d",&n);
    k = GetMaxPow(n);
    printf("공식을 만족하는 k의 최댓값은 %d",k);

    return 0;
}