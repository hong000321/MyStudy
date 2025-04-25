#include <stdio.h>
#include "Test_header.h"


#if FILE_NUM == 10
int my_main(void) {
    int n = 0;

    scanf("%d",&n);
    for(int i = 0 ; i<n ; i++){
        for(int j = 1 ; j<n+1 ; j++){
            printf("%d ",j*(i+1));
        }
        printf("\n");
    }
	
	return 0;
}
#endif
