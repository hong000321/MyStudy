#include <stdio.h>
#include "Test_header.h"


#if FILE_NUM == 15
int my_main(void) {
	int num1 = 15;
	int num2 = ~num1;
	printf("Not 연산의 결과: %d \n", num2);

	return 0;
}
#endif