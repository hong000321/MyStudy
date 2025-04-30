#include <stdio.h>


void rotateArr(int (*arr)[4][4]){
    int tmp_arr[4][4];
    for(int i = 0 ; i<4; i++){
        for(int j=0; j<4; j++){
            tmp_arr[j][3-i] = (*arr)[i][j];
        }
    }

    for(int i = 0 ; i<4; i++){
        for(int j=0; j<4; j++){
            (*arr)[i][j] = tmp_arr[i][j];
        }
    }
}

void printArr(int (*arr)[4][4]){
    for(int i = 0 ; i<4; i++){
        for(int j=0; j<4; j++){
            printf("%3d",(*arr)[i][j]);
        }
        printf("\n");
    }
}


int main(void){
    int arr[4][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    printArr(&arr);
    printf("\n");

    rotateArr(&arr);
    printArr(&arr);
    printf("\n");

    rotateArr(&arr);
    printArr(&arr);
    printf("\n");

    rotateArr(&arr);
    printArr(&arr);

    return 0;
}
