#include <stdio.h>

int main(void)
{
    int arr[5][5] = {0};
    char arr_name[5][4] = {"1","2","3","4","5"};
    char arr_subj[5][4] = {"1","2","3","4","5"};

    for(int i = 0; i<4; i++){
        for(int j = 0; j<4 ; j++){
            printf("%s %s 점수: ", arr_name[i], arr_subj[j]);
            scanf("%d", &arr[i][j]);
        }
    }
    for(int i = 0 ; i<4; i++){
        for(int j = 0; j<4 ; j++){
            arr[i][4] += arr[i][j];
            arr[4][j] += arr[i][j];
            arr[4][4] += arr[i][j];
        }
    }

    printf("\n");
    for(int i = 0 ; i<5; i++){
        for(int j = 0; j<5 ; j++){
            printf("%d ", arr[i][j]);
        }

        printf("\n");
    }

    return 0;
}