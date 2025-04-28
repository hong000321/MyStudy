#include <stdio.h>

int numCheck(int n, int a, int b){
    if(n<a || n>b){
        return 0;
    }
    return 1;
}

int main(void){
    int n1 = 0;
    int n2 = 0;
    scanf("%d %d" , &n1, &n2);
    if(!numCheck(n1,1,10000) || !numCheck(n2,1,10000)){
        printf("INPUT ERROR!");
        return 0;
    }
    

    return 0;
}