#include <stdio.h>

void SimpleFuncOne(int arr1[], int arr2[]){

}
void SimpleFuncOne(int *arr1[], int arr2[]){

}

int main(void){
    
    int num_arr[5] = {1,2,3,4,5};

    int *arr1[5] = {0};
    int *arr2[3][5] = {0};
    
    *arr1 = &num_arr;
    *arr2[2] = &num_arr;

    int **ptr1 = arr1;
    int *(*ptr2)[5] = arr2;
    
    printf("%d %d",*(*ptr1+1), ptr2);

    return 0;
}