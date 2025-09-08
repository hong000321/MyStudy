// https://www.acmicpc.net/problem/1475

#include <stdio.h>
#include <unistd.h>

#define IS_LIMIT_OVER(k) ((k)>1000000) ? (-1) : (((k)<0) ? (-1) : 0)


int main(void){
    int a;
    int set;
    int digit[9] = {0};
    int remain;
    scanf("%d",&a);

    if(IS_LIMIT_OVER(a)){
        return -1;
    }

    while(a!=0){
        remain = a%10;
        if(remain == 9){
            remain = 6;
        }
        digit[remain] += 1;
        a/=10;
    }

    int tmp = 0;
    tmp = digit[6]%2;
    tmp += digit[6]/2;
    digit[6] = tmp;

    int highest = 0;
    for(int i=1; i<9; i++){
        if(digit[highest] <= digit[i]){
            highest = i;
        }
    }

    printf("%d",digit[highest]);
    
    sleep(100);
    return 0;
}