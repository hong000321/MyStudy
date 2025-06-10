/*
문제
삼각형의 높이 N을 입력받아 아래와 같은 모양을 출력하는 프로그램을 작성하시오.
7
* 
 *** 
  ***** 
   ******* 
  ***** 
 *** 
*
입력
삼각형의 높이 N(N의 범위는 100 이하의 양의 홀수)을 입력받는다.

출력
N의 높이에 맞추어 주어진 형태의 모양을 출력한다.
입력된 데이터가 주어진 범위를 벗어나면 "INPUT ERROR!"를 출력한다.
*/
#include <stdio.h>


void nspace(int n){
    for(int i = 0; i<n ; i++){
        printf(" ");
    }
}

void nstar(int n){
    for(int i = 0; i<n ; i++){
        printf("*");
    }
}

int main(void){
    int n;
    scanf("%d",&n);
    if(n<1 || n>100 || n%2==0){
        printf("INPUT ERROR!");
        return 0;
    }

    for(int i = 1; i<=(n/2+1) ; i++){
        int star = i*2-1;
        nspace(i-1);
        nstar(star);
        printf("\n");
    }
    for(int i=(n/2); i>=1 ; i--){
        int star = i*2-1;
        nspace(i-1);
        nstar(star);
        printf("\n");
    }
    


    return 0;
}