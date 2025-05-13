#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int maxof(const int a[], int n){
    int max = a[0];
    for(int i=1; i<n; i++){
        if(a[i]>max) max = a[i];
    }
    return max;
}

int main(void){
    int number;
    printf("사람 수");
    scanf("%d",&number);
    int *height = calloc(number, sizeof(int));
    srand(time(NULL));  // 시간으로 난수의 seed를 초기화 (초기화 없이 사용 시 프로그램을 몇번 실행해도 항상 같은 값을 반환 함.)
    for(int i=0; i<number; i++){
        height[i] = 100+ rand() %90;  //초기화된 난수를 100~189의 범위로 생성.대입 rand()가 생성하는 값은 0~RAND_MAX 값 범위(0x7fff)
        printf("height[%d] = %d\n", i, height[i]);
    }
    printf("최댓값은 %d입니다.\n", maxof(height,number));
    printf("RAND_MAX : %d",RAND_MAX);
    free(height);

    return 0;
}