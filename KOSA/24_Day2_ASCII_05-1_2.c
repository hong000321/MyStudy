#include <stdio.h>
#include "Test_header.h"


#if FILE_NUM == 24
int my_main(void) {
	float num1 = 0.0f;
	float num2 = 0.0f;
	printf("�� �Ǽ� �Է�: \n");
	scanf("%f %f", &num1, &num2);

	printf("��� : \n");
	printf("���ϱ�	: %f \n", num1 + num2);
	printf("����	: %f \n", num1 - num2);
	printf("���ϱ�	: %f \n", num1 * num2);
	printf("������	: %f \n", num1 / num2);


	return 0;
}
#endif