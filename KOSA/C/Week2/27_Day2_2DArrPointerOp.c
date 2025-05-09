#include <stdio.h>


int main(void){
    int arr1[3][2];
    int arr2[2][3];

    printf("arr1:   %p \n", arr1);
    printf("arr1+1: %p \n", arr1+1); //2차원에서 열이 2개임으로 +1을 하게 되면 int 2개가 늘어나서 총 8바이트가 늘어남
    printf("arr1+2: %p \n\n", arr1+2);
    
    printf("arr2:   %p \n", arr2);
    printf("arr2+1: %p \n", arr2+1); //2차원에서 열이 3개임으로 +1을 하게 되면 int 3개가 늘어나서 총 12바이트가 늘어남
    
    
    return 0;
}