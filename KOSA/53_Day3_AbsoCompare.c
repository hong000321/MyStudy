#include <stdio.h>
#include "Test_header.h"


#if FILE_NUM == 53

int AbsoCompare(int num1, int num2);
int GetAbsoValue(int num);


int my_main(void) {
	int num1, num2;
	printf("�� ���� ���� �Է�: ");
	scanf("%d %d", &num1, &num2);
	printf("%d�� %d�� ������ ū ����: %d \n",
		num1, num2, AbsoCompare(num1, num2));
	


	return 0;
}

int AbsoCompare(int num1, int num2) {
	return (GetAbsoValue(num1) > GetAbsoValue(num2))?num1:num2;
}

int GetAbsoValue(int num) {
	return (num<0) ? num*(-1) : num;
}
#endif