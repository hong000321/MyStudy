#include <stdio.h>

#include "Test_header.h"

#if FILE_NUM == 7

int my_main(void) {

	int num1 = 12;

	int num2 = 12;

	printf("num1: %d \n", num1);

	printf("num1++: %d \n", num1++);

	printf("num1: %d \n", num1);

	printf("num2: %d \n", num2);

	printf("++num2: %d \n", ++num2);

	printf("num2: %d \n", num2);

	return 0;

}

#endif