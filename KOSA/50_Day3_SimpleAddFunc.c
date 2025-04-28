#include <stdio.h>
#include "Test_header.h"


#if FILE_NUM == 50

int Add(int num1, int num2) {
	return num1 + num2;
}
int my_main(void) {
	int result;
	result = Add(3, 4);
	printf("µ¡¼À°á°ú1: %d \n", result);
	result = Add(5, 8);
	printf("µ¡¼À°á°ú2: %d \n", result);

	return 0;
}
#endif