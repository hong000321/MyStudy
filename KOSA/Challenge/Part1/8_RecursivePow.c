#include <stdio.h>

int GetPowOf2(int pow){
    if(pow<=0){ //pow의 값이 0이하이면 1을 반환하고 아래의 재귀함수가 더 이상 호출되지 않도록 함.
        return 1;
    }
    return 2*GetPowOf2(--pow); // 2의 n승이기 때문에 pow의 값을 하나씩 빼면서 재귀함수 호출
}

int main(void){
    int pow;
    int result;
    printf("정수 입력 : ");
    scanf("%d",&pow);
    result = GetPowOf2(pow);
    printf("2의 %d승은 %d",pow,result);
    return 0;
}