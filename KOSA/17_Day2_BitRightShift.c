#include <stdio.h>
#include "Test_header.h"


#if FILE_NUM == 17
int my_main(void) {
	int num = -16;
	
	printf("2ĭ �̵� ���: %d \n", num >> 2);
	printf("3ĭ �̵� ���: %d \n", num >> 3);
	return 0;
}
#endif