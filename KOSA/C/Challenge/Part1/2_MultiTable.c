#include <stdio.h>  // scanf, printf를 위한 헤더파일 추가

int main(void){
    int a,b,start,end;
    printf("구구단 시작 끝 입력: ");
    scanf("%d %d",&a, &b);  // a와 b에 구구단 시작과 끝의 값 입력
    start = (a>b)?b:a;      // start에 a,b중 작은 값 대입
    end = (a>b)?a:b;        // end에 a,b중 큰 값 대입

    int i,j;
    for(i=1;i<=9;i++){              // 4 x 1 = 4    5 x 1 = 5 와 같이 가로로 출력하기 위해 단을 외부 반복문으로 설정
        for(j=start; j<=end; j++){  // start(작은 값)부터 end(큰 값) 까지 반복
            printf("%2d x %2d = %2d   ",j,i,j*i);  // 깔끔하게 출력하기 위해 글자 수 출력을 2개로 서식 지정
        }
        printf("\n"); // 각 단의 해당 곱셈이 끝나면 다음 줄로 이동
    }

    return 0;
}