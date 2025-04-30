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
#define ARR_SIZE 10

void printArr(int (*arr)[ARR_SIZE][ARR_SIZE]){
    for(int i = 0 ; i<ARR_SIZE; i++){
        for(int j=0; j<ARR_SIZE; j++){
            int val = (*arr)[i][j];
            if(val != 0)
                printf("%3d ",val);
        }
        printf("\n");
    }
    getchar();
}


int main(void){
    int n;
    int arr[ARR_SIZE][ARR_SIZE] = {0};
    int dir_x = 1; // 1 or -1
    int dir_y = 1; // 1 or -1
    int last_p[2] = {0,0};
    int count = 1;
    scanf("%d",&n);

    for(int j=0; j<n ; j++){
        arr[0][j] = count;
        last_p[1]+=dir_y;
        count++;
    }
    last_p[1]--;
    dir_y *=-1;
    for(int i=(n-1); i>0 ; i--){
        for(int j=0; j<i ; j++){
            last_p[0]+=dir_x;
            arr[last_p[0]][last_p[1]] = count;
            count++;
        }
        dir_x *= -1;
        for(int j=0; j<i ; j++){
            last_p[1]+=dir_y;
            arr[last_p[0]][last_p[1]] = count;
            count++;
        }
        dir_y *= -1;
    }
    printArr(&arr);
    return 0;
}