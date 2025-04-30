/*
문제
삼각형의 높이 n을 입력받은 후 다음과 같은 삼각형 형태로 출력하는 프로그램을 작성하시오.
n = 3
0 0 0 0 0
  1 1 1
    2

입력
삼각형의 크기 n(n의 범위는 50 이하의 홀수)을 입력받는다.

출력
삼각형의 높이를 n에 맞춰서 출력한다. 숫자사이는 공백으로 구분한다.
입력된 데이터가 주어진 범위를 벗어나면 "INPUT ERROR!"을 출력한다.
 */
#include <stdio.h>
#include <string.h>
#define ARR_SIZE 100

void printArr(int (*arr)[ARR_SIZE][ARR_SIZE]){
    for(int i = 0 ; i<ARR_SIZE; i++){
        for(int j=0; j<ARR_SIZE; j++){
            int val = (*arr)[i][j];
            if(val >= 0)
                printf("%d ",val);
            if(val == -1)
                printf("  ");
        }
        printf("\n");
    }
}


int main(void){
    int n;
    int arr[ARR_SIZE][ARR_SIZE];
    memset(arr,-2,sizeof(arr));

    int k=0;
    int count = 1;

    scanf("%d",&n);
    if(n>50 || n<1 || n%2==0){
        printf("INPUT ERROR!\n");
        return 0;
    }
    for(int i=0 ; i<n ; i++){
        for(int j=0; j<k; j++){
            arr[i][j] = -1;
        }
        for(int j=(n-1-k)*2+1; j>0 ;j--){
            arr[i][j+k] = i;
        }
        k++;
    }
    printArr(&arr);
    return 0;
}