#include <stdio.h>
#include "Test_header.h"


#if FILE_NUM == 51

int Add(int num1, int num2) {
	return num1 + num2;
}

void ShowAddResult(int num) {
	printf("������� ���: %d \n", num);
}

int ReadNum(void) {
	int num;
	scanf("%d", &num);
	return num;
}

int HowToUseThisProg(void) {
	printf("�� ���� ������ �Է��Ͻø� ��������� ��µ˴ϴ�. \n");
	printf("��! �׷� �� ���� ������ �Է��ϼ���. \n");
}

int my_main(void) {
	int result, num1, num2;
	HowToUseThisProg();
	num1 = ReadNum();
	num2 = ReadNum();
	result = Add(num1, num2);
	ShowAddResult(result);
	return 0;
}
#endif