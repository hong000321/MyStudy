#include <stdio.h>
#include "Test_header.h"


#if FILE_NUM == 10
int my_main(void) {
	int result;
	int num1, num2;

	printf("정수 one: ");
	scanf("%d", &num1);
	printf("정수 two: ");
	scanf("%d", &num2);

	result = num1 + num2;
	printf("%d +%d = %d \n", num1, num2, result);

	return 0;
}
#endif