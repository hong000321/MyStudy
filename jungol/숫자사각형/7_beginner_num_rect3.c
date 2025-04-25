#include <stdio.h>
#include "Test_header.h"


#if FILE_NUM == 7
int my_main(void) {
    int n = 0;

    scanf("%d",&n);
    for(int i = 1 ; i<n+1 ; i++){
        for(int j = 0 ; j<n ; j++){
            printf("%d ",j*n+i);
        }
        printf("\n");
    }
	
	return 0;
}
#endif
