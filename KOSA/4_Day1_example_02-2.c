#include <stdio.h>
#include "Test_header.h"


#if FILE_NUM == 4
int my_main(void) {
	printf("�� �̸��� ȫ����Դϴ�.\n");
	printf("�� ���̴� %d���̰��.\n", 20);
	printf("���� ��� ���� �������� %d-%d\n", 123, 456);

	return 0;
}
#endif