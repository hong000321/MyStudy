#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <memory.h>

#define swap(type,x,y) do {type t = x; x=y; y=t; } while(0)

int Search(int x[], int xn, int key){
    int probe = xn/2;
    int tn = xn/2;
    int *log = (int *)calloc(xn,sizeof(int));
    int ret = -1;
    memset(log,-1,sizeof(int));
    for(int i=0; i<xn ; i++){
        if(probe>xn-1 || probe<0){ // 배열 크기를 벗어나면(key값을 찾을 수 없으면) -1 반환
            ret = -1;
            break;
        }
        log[i] = x[probe];
        if(x[probe] == key){ // key 값 찾음 
            ret = probe;
            break;
        }else if(x[probe]>key){ // key값이 더 작음
            tn = tn - tn/2;
            probe = probe - tn;
        }else if(x[probe]<key){  // key값이 더 큼
            tn = tn - tn/2;
            probe = probe + tn;
        }
    }
    
    for(int i=0; i<xn; i++){  // 검색 진행한 순서 출력
        printf("%d, ",log[i]);
    }
    printf("\n");
    return ret;
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

    int key = arr[arr_size-1];

    printf("입력 배열 : \n");
    printArr(arr,arr_size);
    sort(arr,arr_size, 1);
    printArr(arr,arr_size);
    key = key;
    int ret = Search(arr, arr_size, key);
    printf("%d 검색 결과 : %d",key,ret);

    free(arr);
    return 0;
}