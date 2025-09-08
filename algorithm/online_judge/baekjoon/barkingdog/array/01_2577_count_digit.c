// https://www.acmicpc.net/problem/2577
#include <stdio.h>
#include <unistd.h>
#define IS_OVER_LIMIT(k) ((k)<100) ? (-1) : (((k)>=1000) ? (-1) : 0)



int main(void){
    int a,b,c;
    int result;
    int remain;
    int num[10] = {0};
    
    scanf("%d %d %d", &a, &b, &c);
    if(IS_OVER_LIMIT(a) || IS_OVER_LIMIT(b) || IS_OVER_LIMIT(c)){
        return -1;
    }
    result = a*b*c;


    while(result!=0){
        remain = result%10;
        num[remain] += 1;
        result/=10;
    }
    for(int i=0; i<10; i++){
        printf("%d\n", num[i]);
    }
    sleep(100000);
    return 0;
}