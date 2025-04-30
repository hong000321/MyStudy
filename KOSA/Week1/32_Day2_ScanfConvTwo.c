#include <stdio.h>

#include "Test_header.h"

#if FILE_NUM == 32

int my_main(void) {

	float num1;

	double num2;

	long double num3;

	printf("실수 입력1(e 표기법으로):");

	scanf("%f", &num1);

	printf("입력된 실수(f) %f \n", num1);

	printf("실수 입력2(e 표기법으로):");

	scanf("%lf", &num2);

	printf("입력된 실수(lf) %f \n", num2);

	printf("실수 입력3(e 표기법으로):");

	scanf("%Lf", &num3);

	printf("입력된 실수(Lf) %f \n", num3);

	return 0;

}

#endif