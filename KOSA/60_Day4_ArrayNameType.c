#include <stdio.h>
#include "Test_header.h"


#if FILE_NUM == 60
int my_main(void) {
	int arr[3] = { 0,1,2 };
	printf("�迭�� �̸�: %p \n", arr);
	printf("ù ��° ���: %p \n", &arr[0]);
	printf("�� ��° ���: %p \n", &arr[1]);
	printf("�� ��° ���: %p \n", &arr[2]);

	return 0;
}
#endif