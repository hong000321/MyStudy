/*
문제

삼각형의 높이 n을 입력 받은 후 출력 예제과 같은 삼각형 형태로 출력하는 프로그램을 작성하시오. 
7
****
 ***
  **
   *
   **
   ***
   ****
입력
100 이하의 홀수인 양의 정수 n이 주어진다.

출력
입력된 데이터가 주어진 범위를 벗어나면 "INPUT ERROR!"을 출력한다. 
'*'과 '*' 사이에는 공백이 없다.
*/
#include <stdio.h>

int num_nok(int a, int x , int y){
    if(a>y || a<x){
        return 1;
    }
    return 0;
}

void draw_star(int size){
    int r_size = size/2 +1;
    for(int i = r_size ; i>0 ; i--){
        for(int j = 0; j<r_size-i ; j++){
            printf(" ");
        }
        for(int j = 0; j<i ; j++){
            printf("*");
        }
        printf("\n");
    }
    for(int i = 2 ; i<=r_size ; i++){
        for(int j = 0; j<r_size-1 ; j++){
            printf(" ");
        }
        for(int j = 0; j<i ; j++){
            printf("*");
        }
        printf("\n");
    }
}

int main(void){
    int n;

    scanf("%d",&n);
    if(num_nok(n,1,100) || n%2==0){
        printf("INPUT ERROR!");
        return 0;
    }
    
    draw_star(n);
    return 0;
}