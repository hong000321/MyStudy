#include <stdio.h>

#include "Test_header.h"

#if FILE_NUM == 25

int my_main(void) {

	char a = 0;

	printf("문자 입력: \n");

	scanf("%c", &a);

	printf("값 : %d", a);

	return 0;

}

#endif