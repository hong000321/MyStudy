#include <stdio.h>

int main(void) {
	float num1 = 0.0f;
	float num2 = 0.0f;
	printf("두 실수 입력: \n");
	scanf("%f %f", &num1, &num2);
	printf("결과 : \n");
	printf("더하기	: %f \n", num1 + num2);
	printf("빼기	: %f \n", num1 - num2);
	printf("곱하기	: %f \n", num1 * num2);
	printf("나누기	: %f \n", num1 / num2);

	return 0;
}