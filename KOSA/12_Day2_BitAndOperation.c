#include <stdio.h>
#include "Test_header.h"


#if FILE_NUM == 12
int my_main(void) {
	int num1 = 15;
	int num2 = 20;
	int num3 = num1 & num2;
	printf("AND ������ ���: %d \n", num3);

	return 0;
}
#endif