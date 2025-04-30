#include <stdio.h>

#include "Test_header.h"

#if FILE_NUM == 52

int NumberCompare(int num1, int num2);

int my_main(void) {

	printf("3과 4중에서 큰 수는 %d 이다. \n", NumberCompare(3, 4));

	printf("7과 2중에서 큰 수는 %d 이다. \n", NumberCompare(7, 2));

	return 0;

}

int  NumberCompare(int num1, int num2) {

	if (num1 > num2)

		return num1;

	else

		return num2;

}

#endif