#include <stdio.h>

// 입력된 인자가 소수인지 아닌지 확인 후 맞으면 1 아니면 0을 반환하는 함수
int IsPrimeNumber(int a){
    int i;
    for(i=2; i<a ;i++){
        if(a%i==0){
            return 0;
        }
    }
    return 1;
}

int main(void){
    int count = 0;
    int i = 2;
    while(1){
        if(count>=10){ // 문제는 10개 까지 출력이기 때문에 10개로 제한
            break;
        }
        if(IsPrimeNumber(i)){ // 만약 소수라면 해당 값을 출력하고 count를 1증가
            printf("%d ",i);
            count++;
        }
        i++; //확인 할 값을 1씩 증가
    }

    return 0;
}