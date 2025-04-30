#include <stdio.h>

#include "Test_header.h"

#if FILE_NUM == 3

int my_main(void) {

	printf("Hello Everybody\n");

	printf("%d\n", 1234);

	printf("%d %d\n", 10, 20);

	return 0;

}

#endif