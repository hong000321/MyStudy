#include <stdio.h>
#include "Test_header.h"


#if FILE_NUM == 26


int my_main(void) {
	int b = 0;

	printf("정수 입력: \n");
	scanf("%d", &b);
	printf("값 : %c", b);
	return 0;
}
#endif