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
    int small_i=0;
    int small;
    for(j=0;j<xn;j++){
        small = x[j];
        small_i = j;
        for(i=j;i<xn;i++){
            if(small>x[i]){
                small=x[i];
                small_i = i;
            }
        }
        swap(int,x[small_i],x[j]);
        printf("%d <-> %d\n",x[j],x[small_i]);
        printArr(x,xn);
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