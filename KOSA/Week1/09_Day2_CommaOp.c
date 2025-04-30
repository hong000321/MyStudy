#include <stdio.h>

#include "Test_header.h"

#if FILE_NUM == 9

int my_main(void) {

	int num1 = 1;

	int num2 = 2;

	printf("Hello "), printf("world!  \n");

	num1++, num2++;

	printf("%d ", num1), printf("%d ", num2), printf("\n");

	return 0;

}

#endif