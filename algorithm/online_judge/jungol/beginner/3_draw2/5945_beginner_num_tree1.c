/*
문제
삼각형의 높이 n를 입력받은 후 다음과 같은 삼각형 형태로 출력하는 프로그램을 작성하시오.
    n=5 
    1
    3  2
    4  5  6
    10 9  8  7
    11 12 13 14 15

< 처리조건 >
숫자의 진행 순서는 처음에 왼쪽에서 오른쪽으로 진행 한다.
다음줄은 방향을 바꾸어서 오른쪽에서 왼쪽으로 진행한다.
1, 2를 n까지 반복한다.


입력
삼각형의 크기 n(n의 범위는 50 이하의 홀수)을 입력받는다.

출력
삼각형의 높이는 n에 맞춰서 출력한다. 숫자사이는 공백으로 구분한다.
입력된 데이터가 주어진 범위를 벗어나면 "INPUT ERROR!"을 출력한다.
 */
#include <stdio.h>
#define ARR_SIZE 100

void printArr(int (*arr)[ARR_SIZE][ARR_SIZE]){
    for(int i = 0 ; i<ARR_SIZE; i++){
        for(int j=0; j<ARR_SIZE; j++){
            int val = (*arr)[i][j];
            if(val != 0)
                printf("%d ",val);
        }
        if((*arr)[i+1][0] != 0)
            printf("\n");
    }
}


int main(void){
    int n;
    int arr[ARR_SIZE][ARR_SIZE] = {0};
    int x=0, k=1;
    int count = 1;

    scanf("%d",&n);
    if(n>50 || n<1 || n%2==0){
        printf("INPUT ERROR!\n");
        return 0;
    }
    for(int i=0 ; i<((n/2)+(n%2)) ; i++){
        x = i*2;
        for(int y=0; y<k ; y++){
            arr[x][y] = count;
            count++;
        }
        k++;
        if(x==n-1){
            break;
        }
        for(int y=k-1; y>=0 ; y--){
            arr[x+1][y] = count;
            count++;
        }
        k++;
    }

    printArr(&arr);
    return 0;
}