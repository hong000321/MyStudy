#include <stdio.h>
#include "Test_header.h"


#if FILE_NUM == 27
int my_main(void) {
	double num1 = 245;
	int num2 = 3.1415;
	int num3 = 256;
	char ch = num3;

	double num_d = 3.141592;
	char double_char = num_d;
	int double_int = num_d;
	float double_float = num_d;
	
	float num_f = 3.141592;
	double float_double = num_f;
	int float_int = num_f;

	printf("double -> char	: %d\n", double_char);
	printf("double -> int	: %d\n", double_int);
	printf("double -> float	: %d\n", double_float);


	printf("float -> double	: %lf\n", float_double);
	printf("float -> int	: %d\n", float_int);

	printf("���� 245�� �Ǽ���: %f \n", num1);
	printf("�Ǽ� 3.1415�� ������: %d \n", num2);
	printf("ū ���� 129�� ���� ������: %d \n", ch);

	return 0;
}
#endif