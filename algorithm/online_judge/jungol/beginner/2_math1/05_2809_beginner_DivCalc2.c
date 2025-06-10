#include <stdio.h>

int num_ok(int a, int x, int y){
    if(a<x || a>y){
        return 0;
    }
    return 1;
}

int main(void){
    int n;
    int arr[1000] = {1};
    int count = 1;
    scanf("%d",&n);

    if(!(num_ok(n,2,2100*1000*1000))){
        printf("INPUT ERROR");
    }
    int i = 2;
    while(i<(n/arr[count-1])){
        if(n%i==0){
            arr[count] = i;
            count++;
        }
        i++;
    }
    int j = 0;
    for(int i = 1 ; i<=count ; i++){
        arr[count+i-1-j] = n/arr[count-i];
        if(arr[count-i] == arr[count+i-1]){
            j = 1;
        }
        
    }
    for(int i = 0 ; i<1000 ; i++){
        if(arr[i] != 0){
            printf("%d ",arr[i]);
        }
    }
    return 0;
}