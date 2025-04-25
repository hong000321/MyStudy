#include <stdio.h>
#include "Test_header.h"


#if FILE_NUM == 13

int my_main(void) {
    int n = 0;
    int ascii_a = 65;
    int index = 1;
    int array[100][100] = {0};

    scanf("%d",&n);
    int k = 0;
    for(int i = 0 ; i<n ; i++){
        k = 0;
        for(int j = (n-1) ; (i+k<n)&&(j>-1) ; j--){
            array[i+k][j] = index;
            index++;
            k++;
        }
    }
    for(int i = 0 ; i<n ; i++){
        for(int j = 0; j<n ;j++){
            if(array[i][j]==0){
                printf("  ");
                continue;
            }
            printf("%c ", ascii_a+((array[i][j]-1)%26));
        }
        printf("\n");
    }
	
	return 0;
}
#endif
