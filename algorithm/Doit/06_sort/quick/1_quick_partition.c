#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define swap(type,x,y) do {type t = x; x=y; y=t; } while(0)

void sort(int x[], int  xn, int left){
    int pivot = x[left + xn/2];
    int pl=left;
    int pr=left+xn-1;
    printf("pivot = %d (%d)\n",left+xn/2,pivot);
    do{
        while(x[pl]<pivot) pl++;
        while(x[pr]>pivot) pr--;
        if(pl <= pr){
            printf("swap : %d(%d) | %d(%d)\n", pl, x[pl], pr, x[pr]);
            swap(int, x[pl], x[pr]);
            pl++;
            pr--;
        }
    }while(pl<=pr);
    printf("피벗의 값은 %d 입니다.\n",pivot);
    printf("피벗 이하의 그룹\n");
    for(int i = 0; i<=pl-1; i++){
        printf("%d ", x[i]);
    }
    putchar('\n');


    if(pl > pr+1){
        printf("피벗과 일치하는 그룹\n");
        for(int i = pr+1; i<=pl-1; i++){
            printf("%d ", x[i]);
        }
        putchar('\n');
    }

    
    printf("피벗 이상의 그룹\n");
    for(int i = pr+1; i<xn; i++)
        printf("%d ", x[i]);
    putchar('\n');

    
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

    printf("입력 배열 : \n");
    printArr(arr,arr_size);
    //===================== 배열 입력 완료 =========================
    sort(arr,arr_size,0);
    printArr(arr,arr_size);

    free(arr);
    return 0;
}