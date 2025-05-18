#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define swap(type,x,y) do {type t = x; x=y; y=t; } while(0)

void sort(int x[], int left, int right){
    int pl=left;                // 왼쪽 끝에서 스캔 시작
    int pr=right;               // 오른쪽 끝에서 스캔 시작
    int pivot = x[(pr+pl)/2];   // 중앙 혹은 중앙 왼쪽 요소의 값
    printf("pivot = %d (%d)\n",(pr+pl)/2,pivot);
    do{
        while(x[pl]<pivot) pl++;
        while(x[pr]>pivot) pr--;
        if(pl <= pr){
            printf("swap : %d(%d) | %d(%d)\n", pl, x[pl], pr, x[pr]);
            swap(int, x[pl], x[pr]);
            pl++;
            pr--;
        }
        printf("pl = %d , pr = %d\n",pl,pr);
    }while(pl<pr);
    if(left < pr) sort(x, left,pr);
    if(right > pl) sort(x,pl,right);
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
    int arr_size = 5 + rand()%5;
    int *arr = (int *)calloc(arr_size,sizeof(int));

    int a_min = 1;
    int a_max = 9;

    for(int i=0; i<arr_size; i++){
        arr[i] = a_min + rand()%a_max;
    }
    int arr2[8] = {9,4,2,3,7,1,6,5};
    printf("입력 배열 : \n");
    printArr(arr2,8);
    //===================== 배열 입력 완료 =========================
    sort(arr2,0,8-1);
    printArr(arr2,8);

    free(arr);
    return 0;
}