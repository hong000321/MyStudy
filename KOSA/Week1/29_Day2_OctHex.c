#include <stdio.h>

#include "Test_header.h"

#if FILE_NUM == 29

int my_main(void) {

	int num1 = 17, num2 = 13;

	printf("%o %#o \n", num1, num1);

	printf("%x %#x \n", num2, num2);

	return 0;

}

#endif