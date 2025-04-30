#include <stdio.h>

#include "Test_header.h"

#if FILE_NUM == 45

int my_main(void) {

	int num, abs;

	printf("정수 입력: ");

	scanf("%d", &num);

	abs = num > 0 ? num : num * (-1);

	printf("절댓값: %d \n", abs);

	return 0;

}

#endif