#include <stdio.h>

#include "Test_header.h"

#if FILE_NUM == 17

int my_main(void) {

	int num = -16;

	printf("2칸 이동 결과: %d \n", num >> 2);

	printf("3칸 이동 결과: %d \n", num >> 3);

	return 0;

}

#endif