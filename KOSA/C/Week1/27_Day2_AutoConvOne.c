#include <stdio.h>

int main(void) {
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
	printf("정수 245를 실수로: %f \n", num1);
	printf("실수 3.1415를 정수로: %d \n", num2);
	printf("큰 정수 129를 작은 정수로: %d \n", ch);

	return 0;
}