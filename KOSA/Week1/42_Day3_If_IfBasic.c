#include <stdio.h>

#include "Test_header.h"

#if FILE_NUM == 42

int my_main(void) {

	int num;

	printf("정수 입력: ");

	do {

		num = 9999;

		scanf("%d", &num);

		if (num < 0)

			printf("입력 값은 0보다 작다. \n");

		if (num > 0)

			printf("입력 값은 0보다 크다. \n");

		if (num == 0)

			printf("입력 값은 0이다. \n");

	} while (num != 9999);

	return 0;

}

#endif