#include <stdio.h>
#include "Test_header.h"


#if FILE_NUM == 57
int my_main(void) {
	char str[] = "Good morning!";
	printf("�迭 str�� ũ��: %d \n", sizeof(str));
	printf("�� ���� ������ ���: %c \n", str[13]);
	printf("�� ���� ������ ���: %d \n", str[13]);

	str[12] = '?';
	printf("���ڿ� ���: %s \n", str);
	return 0;
}
#endif