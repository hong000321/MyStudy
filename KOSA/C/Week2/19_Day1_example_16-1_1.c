#include <stdio.h>

int main(void){
    int arr[3][9] = {0};
    int i, j;
    for(i = 0; i<3; i++){
        for(j = 0; j<9 ; j++){
            arr[i][j] = (i+2)*(j+1);
        }
    }

    for(i = 0; i<3; i++){
        for(j = 0; j<9 ; j++){
            printf("%d * %d = %d \n",(i+2), (j+1),arr[i][j]);
        }
        printf("\n");
    }

    
    
    return 0;
}