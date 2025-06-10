/*
삼각형의 높이 n과 종류 m을 입력 받은 후 다음과 같은 삼각형 형태로 출력하는 프로그램을 작성하시오.
*           ****            *
**          ***            ***
***         **            *****
****        *            *******

입력
삼각형의 크기 n(n의 범위는 100 이하의 자연수)과 종류 m(m은 1부터 3사이의 자연수)을 입력받는다.

출력
위에서 언급한 3가지 종류를 입력에서 들어온 높이 n과 종류 m에 맞춰서 출력한다.
입력된 데이터가 주어진 범위를 벗어나면 "INPUT ERROR!"을 출력한다.
*/
#include <stdio.h>

int num_nok(int a, int x , int y){
    if(a>y || a<x){
        return 1;
    }
    return 0;
}

void draw_2(int size){
    for(int i = size; i>0 ; i--){
        for(int j=0; j<i ; j++){
            printf("*");
        }
        printf("\n");
    }
}

void draw_1(int size){
    for(int i = 1; i<=size ; i++){
        for(int j=0; j<i ; j++){
            printf("*");
        }
        printf("\n");
    }
}

void draw_3(int size){
    int r_size=0;
    for(int i = 1; i<=size ; i++){
        r_size = i*2-1;
        for(int j=size-i; j>0 ; j--){
            printf(" ");
        }
        for(int j=0; j<r_size ; j++){
            printf("*");
        }
        printf("\n");
    }
}


int main(void){
    int n , m ;

    scanf("%d %d",&n, &m);
    if(num_nok(n,1,100)||num_nok(m,1,3)){
        printf("INPUT ERROR!");
        return 0;
    }
    
    switch (m)
    {
    case 1:
        draw_1(n);
        break;
    case 2:
        draw_2(n);
        break;
    case 3:
        draw_3(n);
        break;
    }


    return 0;
}