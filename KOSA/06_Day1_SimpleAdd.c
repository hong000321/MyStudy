#include <stdio.h>
#include "Test_header.h"


#if FILE_NUM == 6
int my_main(void) {
	int num1 = 3;
	int num2 = 4;
	int result = num1 + num2;

	printf("덧셈 결과: %d \n", result);
	printf("%d+%d=%d \n", num1, num2, result);
	printf("%d와(과) %d의 합은 %d입니다.\n", num1, num2, result);

	return 0;
}
#endif