#include <stdio.h>
#define ARR_SIZE 10

void printArr(int (*arr)[ARR_SIZE][ARR_SIZE]){
    for(int i = 0 ; i<ARR_SIZE; i++){
        for(int j=0; j<ARR_SIZE; j++){
            int val = (*arr)[i][j];
            if(val != 0)
                printf("%3d ",val);
        }
        printf("\n");
    }
    getchar();
}


int main(void){
    int n;
    int arr[ARR_SIZE][ARR_SIZE] = {0};
    int dir_x = 1; // 1 or -1
    int dir_y = 1; // 1 or -1
    int last_p[2] = {0,0};
    int count = 1;
    scanf("%d",&n);

    for(int j=0; j<n ; j++){
        arr[0][j] = count;
        last_p[1]+=dir_y;
        count++;
    }
    last_p[1]--;
    dir_y *=-1;
    for(int i=(n-1); i>0 ; i--){
        for(int j=0; j<i ; j++){
            last_p[0]+=dir_x;
            arr[last_p[0]][last_p[1]] = count;
            count++;
        }
        dir_x *= -1;
        for(int j=0; j<i ; j++){
            last_p[1]+=dir_y;
            arr[last_p[0]][last_p[1]] = count;
            count++;
        }
        dir_y *= -1;
    }
    printArr(&arr);
    return 0;
}