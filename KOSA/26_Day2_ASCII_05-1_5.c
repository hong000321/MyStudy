#include <stdio.h>
#include "Test_header.h"


#if FILE_NUM == 26


int my_main(void) {
	int b = 0;

	printf("���� �Է�: \n");
	scanf("%d", &b);
	printf("�� : %c", b);
	return 0;
}
#endif