#include <stdio.h>
#include "Test_header.h"


#if FILE_NUM == 41
int my_main(void) {
	int total = 0, num = 0;

	do {
		printf("���� �Է�(0 to quit): ");
		scanf("%d", &num);
		total += num;

	} while (num != 0);
	printf("�հ�: %d \n", total);
	
	return 0;
}
#endif