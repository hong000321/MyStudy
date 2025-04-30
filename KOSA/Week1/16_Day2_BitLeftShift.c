#include <stdio.h>

#include "Test_header.h"

#if FILE_NUM == 16

int my_main(void) {

	int num = 15;

	int result1 = num << 1;

	int result2 = num << 2;

	int result3 = num << 3;

	printf("1칸 이동 결과: %d \n", result1);

	printf("2칸 이동 결과: %d \n", result2);

	printf("3칸 이동 결과: %d \n", result3);

	return 0;

}

#endif