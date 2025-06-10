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
    int i,j,h;
    int tmp;
    for(int h=xn/2;h>0;h/=2){
        for(i=h;i<xn;i++){
            tmp = x[i];
            for(j=i-h; j>=0 && x[j]>tmp;j-=h){
                x[j+h] = x[j];
            }
            x[j+h] = tmp;
        }
    }
}


int main(void){
    srand(time(NULL));
    int arr_size = 10 + rand()%10;
    int *arr = (int *)calloc(arr_size,sizeof(int));

    int a_min = 10;
    int a_max = 100;

    for(int i=0; i<arr_size; i++){
        arr[i] = a_min + rand()%(a_max-a_min);
    }
    // int x[] = {109, 105, 47, 83, 32, 43, 68, 79, 61, 30, 29, 96, 96, 72, 95, 60, 60};
    int x[] = {104, 92, 31, 82, 86, 74, 54, 28, 107, 88, 85, 97, 59, 52, 34, 108, 42, 39};
    arr=x;
    int xn = sizeof(x)/sizeof(int);
    arr_size = xn;
    
    printf("입력 배열 : \n");
    printArr(arr,arr_size);
    sort(arr,arr_size);
    
    printf("출력 배열 : \n");
    printArr(arr,arr_size);
    return 0;
}