#include <stdio.h>
#include "Test_header.h"



#if FILE_NUM == 52

int NumberCompare(int num1, int num2);

int my_main(void) {
	printf("3�� 4�߿��� ū ���� %d �̴�. \n", NumberCompare(3, 4));
	printf("7�� 2�߿��� ū ���� %d �̴�. \n", NumberCompare(7, 2));

	return 0;
}

int  NumberCompare(int num1, int num2) {
	if (num1 > num2)
		return num1;
	else
		return num2;
}
#endif