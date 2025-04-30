#include <stdio.h>

#include "Test_header.h"

#if FILE_NUM == 55

void Add(int val);

int num;

int my_main(void) {

	printf("num: %d \n", num);

	Add(3);

	printf("num: %d \n", num);

	num++;

	printf("num: %d \n", num);

	return 0;

}

void Add(int val) {

	num += val;

}

#endif