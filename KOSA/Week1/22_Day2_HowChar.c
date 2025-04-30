#include <stdio.h>

#include "Test_header.h"

#if FILE_NUM == 22

int my_main(void) {

	char ch1 = 'A', ch2 = 65;

	int ch3 = 'Z', ch4 = 90;

	printf("%c %d \n", ch1, ch1);

	printf("%c %d \n", ch2, ch2);

	printf("%c %d \n", ch3, ch3);

	printf("%c %d \n", ch4, ch4);

	return 0;

}

#endif