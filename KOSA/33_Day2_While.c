#include <stdio.h>
#include "Test_header.h"


#if FILE_NUM == 33
int my_main(void) {
	int num = 0;
	while (num < 3) {
		printf("hello world! %d \n", num);
		num++;
	}
	return 0;
}
#endif