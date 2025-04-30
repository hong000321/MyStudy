#include <stdio.h>

#include "Test_header.h"

#if FILE_NUM == 34

int my_main(void) {

	int input = 0;

	scanf("%d", &input);

	while (input--) {

		printf("Hello World!\n");

	}

	return 0;

}

#endif