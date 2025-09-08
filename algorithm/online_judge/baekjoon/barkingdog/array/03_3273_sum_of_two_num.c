//https://www.acmicpc.net/problem/3273

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


// (1 ≤ n ≤ 100000, 1 ≤ x ≤ 2000000) (1 ≤ *k ≤ 1000000)
#define IS_LIMIT_OVER(var,a,b) ((var)<(a)) ? (-1) : (((var)>(b)) ? (-1) : (0))
#define IS_EQUL(a,b) ((a)==(b))
int main(void){
    int n;
    int k[100000];
    int x;
    int result = 0;

    scanf("%d", &n);
    if(IS_LIMIT_OVER(n,1,100000)){
        return -1;
    }

    // k = (int *)malloc(n*sizeof(int));
    for(int i=0; i<n; i++){
        scanf("%d",&k[i]);
        if(IS_LIMIT_OVER(k[i],1,1000000)){
            return -1;
        }
    }

    scanf("%d", &x);
    if(IS_LIMIT_OVER(x,1,2000000)){
        return -1;
    }

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(IS_EQUL(x, k[i]+k[j])){
                result++;
            }
        }
    }

    printf("%d\n",result);

    sleep(1000);

    return 0;
}