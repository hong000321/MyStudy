#include <stdio.h>
#include "Test_header.h"


#if FILE_NUM == 28
int my_main(void) {
	int num1 = 3, num2 = 4;
	double divResult;
	divResult = num1 / num2; //������ �� ó�� �� �� �� ��� ��(0) �� ���� divResult�� ���Ե����� ����� 0.0���� ����
	printf("������ ���: %f \n", divResult);

	return 0;
}
#endif