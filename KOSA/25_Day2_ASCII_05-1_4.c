#include <stdio.h>
#include "Test_header.h"


#if FILE_NUM == 25


int my_main(void) {
	char a = 0;


	printf("���� �Է�: \n");
	scanf("%c", &a);
	printf("�� : %d", a);
	return 0;
}
#endif