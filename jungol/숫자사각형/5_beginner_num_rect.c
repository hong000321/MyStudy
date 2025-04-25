#include <stdio.h>
#include "Test_header.h"


#if FILE_NUM == 5
int my_main(void) {
    int n = 0;
    int m = 0;

    scanf("%d %d",&n, &m);
    for(int i = 0 ; i<n ; i++){
        for(int j = 1 ; j<m+1 ; j++){
            printf("%d ",i*m+j);
        }
        printf("\n");
    }
	
	

	return 0;
}
#endif
