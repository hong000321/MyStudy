#include <stdio.h>

void ComplexFuncOne(int *arr1[3], int *(*arr2)[5]){

}
void ComplexFuncTwo(int **arr1[5], int ***(*arr2)[5]){

}

int main(void){
    int arr[2][2][2] = {1,2,3,4,5,6,7,8};
    printf("%d \n", arr[1][0][1]);
    printf("%d \n", (*arr[1])[1]);//
    printf("%d \n", *(*arr[1]+1));//** */
    printf("%d \n", (*(arr+1))[0][1]);//
    printf("%d \n", (*(*(arr+1)))[1]);//
    printf("%d \n", (*(*(*(arr+1)))+1));//
    printf("%d \n", *(arr[1][0]+1));//
    printf("%d \n", *(&arr[0][0][0]+1+0*2+1*4));//

    return 0;
}