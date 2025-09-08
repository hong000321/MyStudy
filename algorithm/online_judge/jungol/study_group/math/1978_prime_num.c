#include <stdio.h>
#include <stdlib.h>

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

#define N_MAX 100
#define I_MAX 1000

int main(void){
    
    int n, cnt;
    int *nArr;
    scanf("%d",&n);
    nArr = (int *)calloc(n,sizeof(int));
    if(n>N_MAX){
        return -1;
    }

    for(int i=0; i<n; i++){
        scanf("%d",&nArr[i]);
        if(nArr[i]>I_MAX){
            return -1;
        }
    }

    for(int i=0; i<n; i++){
        if(is_prime_num(nArr[i])){
            cnt++;
        }
    }
    printf("%d\n",cnt);
    scanf("%d",&n);
    return 0;
}