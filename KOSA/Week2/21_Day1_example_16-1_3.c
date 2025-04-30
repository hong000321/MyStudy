#include <stdio.h>

int main(void){
    int arr_a[2][4] = {1,2,3,4,5,6,7,8};
    int arr_b[4][2] = {0};

    for(int i = 0; i<2 ; i++){
        for(int j = 0; j<4 ; j++){
            arr_b[j][i] = arr_a[i][j];
        }
    }

    for(int i = 0; i<4 ; i++){
        for(int j = 0; j<2 ; j++){
            printf("%d ", arr_b[i][j]);
        }
        printf("\n");
    }
    
    
    return 0;
}