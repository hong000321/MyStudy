#include <stdio.h>

#include "Test_header.h"

#if FILE_NUM == 58

int my_main(void) {

	int num1 = 100, num2 = 100;

	int* pnum;

	pnum = &num1;

	(*pnum) += 30;

	pnum = &num2;

	(*pnum) -= 30;

	printf("num1:%d, num2:%d \n", num1, num2);

	return 0;

}

#endif