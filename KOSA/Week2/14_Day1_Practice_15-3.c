#include <stdio.h>

void printOdd(int arr[]){
    for(int i = 0 ; i<10 ; i++){
        if(arr[i]%2 == 1)
        printf("%d ", arr[i]);
    }
}
void printEven(int arr[]){
    for(int i = 0 ; i<10 ; i++){
        if(arr[i]%2 == 0)
        printf("%d ", arr[i]);
    }
}


int main(void){
    int arr_a[10] = {0};
    for(int i = 0 ; i<10 ; i++){
        scanf("%d",&arr_a[i]);
    }

    printOdd(&arr_a[0]);
    printEven(&arr_a[0]);
    return 0;
}