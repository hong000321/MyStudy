#include <stdio.h>
#include "Test_header.h"


#if FILE_NUM ==21
int my_main(void) {
	double rad = 0;
	double area = 0;
	printf("���� ������ �Է�: ");
	scanf_s("%lf", &rad);

	area = rad * rad * 3.1415;
	printf("���� ����: %lf \n", area);

	return 0;
}
#endif