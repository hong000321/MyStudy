#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define swap(type,x,y) do {type t = x; x=y; y=t; } while(0)

int Search(int x[], int xn){

}

int sort(int x[], int  xn, int up){
    int i, j;
    for(i=0; i<xn-1; i++){
        if(up){
           for(j=0; j<xn-1-i; j++){
                if(x[j]>x[j+1]){
                    swap(int,x[j],x[j+1]);
                }
            }
        }else{
            for(j=xn-1-i; j>=0; j--){
                if(x[j]>x[j+1]){
                    swap(int,x[j],x[j+1]);
                }
            }
        }
    }
}

int printArr(int x[], int xn){
    printf("size = %d\n[",xn);
    for(int i=0; i<xn; i++){
        printf("%d, ",x[i]);
    }
    printf("\b\b]\n\n");
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
    sort(arr,arr_size, 1);
    printArr(arr,arr_size);
    Search(arr, arr_size);


    free(arr);
    return 0;
}