#include <stdio.h>
#include "Test_header.h"


#if FILE_NUM == 32
int my_main(void) {
	float num1;
	double num2;
	long double num3;

	printf("�Ǽ� �Է�1(e ǥ�������):");
	scanf("%f", &num1);
	printf("�Էµ� �Ǽ�(f) %f \n", num1);

	printf("�Ǽ� �Է�2(e ǥ�������):");
	scanf("%lf", &num2);
	printf("�Էµ� �Ǽ�(lf) %f \n", num2);

	printf("�Ǽ� �Է�3(e ǥ�������):");
	scanf("%Lf", &num3);
	printf("�Էµ� �Ǽ�(Lf) %f \n", num3);


	return 0;
}
#endif