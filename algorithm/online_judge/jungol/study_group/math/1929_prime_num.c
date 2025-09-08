/**
 * 문제
 * M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.
 * 
 * 입력
 * 첫째 줄에 자연수 M과 N이 빈 칸을 사이에 두고 주어진다. (1 ≤ M ≤ N ≤ 1,000,000) M이상 N이하의 소수가 하나 이상 있는 입력만 주어진다.
 * 
 * 출력
 * 한 줄에 하나씩, 증가하는 순서대로 소수를 출력한다.
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MIN_N 1
#define MAX_N 1000000

char *flag;

void setFlag(int index, int value){
    if(value == 0){
        flag[index/4] &= ~(0x01 << (index%4));
    }else if(value == 1){
        flag[index/4] |= (0x01 << (index%4));
    }else{
        perror("unknown input flag!!");
    }
}

int isFlagTrue(int index){
    return (flag[index/4]) & (0x01 << (index%4)) ;
}

int is_prime_num(int a){
    if (a < 2) return 0;
    int max_a = a/2;
    int last_div = 2;
    for(int i=last_div; i<=max_a; i++){
        if(a%i==0){
            return 0;
        }
        last_div = i;
        max_a = a/last_div;
    }

    return 1;
}

int main(void){
    int m,n;
    flag = (char *)calloc((MAX_N/4)+1,sizeof(char));
    memset(flag,0xFF,(MAX_N/4)+1);

    scanf("%d %d",&m,&n);


    if( m<MIN_N || m>MAX_N || n<MIN_N || n>MAX_N || m>n ){
        return 0;
    }
    // printf("2\n");
    setFlag(1,0);
    for(int i=2; i*i<=n ; i++){
        for(int j=i*i; j<=n; j+=i){
            setFlag(j,0);
        }
    }
    for(int i=m; i<=n; i++){
        if(isFlagTrue(i)){
            printf("%d\n",i);
        }
    }

    scanf("%d");

    return 0;
}