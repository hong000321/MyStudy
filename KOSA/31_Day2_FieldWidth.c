#include <stdio.h>
#include "Test_header.h"


#if FILE_NUM == 31
int my_main(void) {
	printf("%-8s %14s %5s \n", "��  ��", "�����а�", "�г�");
	printf("%-8s %14s %5d \n", "�赿��", "���ڰ���", 3);
	printf("%-8s %14s %5d \n", "������", "��ǻ�Ͱ���", 2);
	printf("%-8s %14s %5d \n", "�Ѽ���", "�̼�������", 4);
	return 0;
}
#endif