#include <stdio.h>
#include "Test_header.h"


#if FILE_NUM == 42
int my_main(void) {
	int num;
	printf("���� �Է�: ");
	

	do {
		num = 9999;
		scanf("%d", &num);
		if (num < 0)
			printf("�Է� ���� 0���� �۴�. \n");
		if (num > 0)
			printf("�Է� ���� 0���� ũ��. \n");
		if (num == 0)
			printf("�Է� ���� 0�̴�. \n");

	} while (num != 9999);
	
	return 0;
}
#endif