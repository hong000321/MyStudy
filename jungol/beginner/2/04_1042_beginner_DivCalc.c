#include <stdio.h>

int num_ok(int a, int x, int y){
    if(a>y || a<x){
        return 0;
    }
    return 1;
}

int find_div(int n, int k){
    int d_cnt = 0;
    int loop_cnt = 0;
    while(d_cnt != k){
        if(loop_cnt>n){
            return 0;
        }
        loop_cnt++;
        if(n%loop_cnt == 0){
            //printf("%d %d \n",n, loop_cnt);
            d_cnt++;
        }
        //printf(".");
    }
    return loop_cnt;
}

int main(void){
    int n,k;
    scanf("%d %d",&n,&k);

    if(!(num_ok(n,1,10000)||num_ok(k,1,n))){
        printf("INPUT ERROR");
    }
    
    printf("%d",find_div(n,k));
    
    return 0;
}