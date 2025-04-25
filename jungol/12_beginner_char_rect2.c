#include <stdio.h>
#include "Test_header.h"


#if FILE_NUM == 12

int my_main(void) {
    int n = 0;
    int ascii_a = 65;
    int index = 0;

    scanf("%d",&n);

    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<n ; j++){
            if((j&0x01) == 1){ //짝수 열
                index = (j+1)*n-i-1;
            }else{ // 홀수 열
                index = j*n+i;
            }
            printf("%c ",ascii_a+(index%26));
        }
        printf("\n");
    }
	
	return 0;
}
#endif
