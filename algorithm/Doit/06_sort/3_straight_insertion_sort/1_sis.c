#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define swap(type,a,b) do{type tmp=a;a=b;b=tmp;}while(0)


int printArr(int x[], int xn){
    printf("size = %d\n[",xn);
    for(int i=0; i<xn; i++){
        printf("%d, ",x[i]);
    }
    printf("\b\b]\n\n");
}

int sort(int x[], int xn){
    int i,j;
    int tmp;
    for(i=0;i<xn-1;i++){
        tmp=x[i+1];
        for(j=i;j>=0 && x[j]>tmp; j--){
            x[j+1] = x[j];
        }
        x[j+1]=tmp;
    }
}

int main(void){
    srand(time(NULL));
    int arr_size = 10 + rand()%10;
    int *arr = (int *)calloc(arr_size,sizeof(int));

    int a_min = 10;
    int a_max = 100;

    for(int i=0; i<arr_size; i++){
        arr[i] = a_min + rand()%a_max;
    }

    printf("입력 배열 : \n");
    printArr(arr,arr_size);
    sort(arr,arr_size);
    
    printf("출력 배열 : \n");
    printArr(arr,arr_size);
    return 0;
}