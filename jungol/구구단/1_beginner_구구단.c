#include <stdio.h>
#include "Test_header.h"


#if FILE_NUM == 1
int my_main(void) {
	int val1 = 0;
	int val2 = 0;

	while(1){
		scanf("%d %d", &val1, &val2);
		if ((val1 < 2) || (val1 > 9) || (val2 < 2) || (val2 > 9)) {
			printf("INPUT ERROR!");
			continue;
		}

		for (int i = 1; i < 10; i++) {
			if(val1>val2){
				for (int j = val1; j > val2-1; j--) {
					printf("%d * %d = %2d", j, i, j * i);
					printf("   ");
				}
			}else{
				for (int j = val1; j < (val2 + 1); j++) {
					printf("%d * %d = %2d", j, i, j * i);
					printf("   ");
				}
			}
			printf("\n");
		}
		break;
	}
	

	return 0;
}
#endif
