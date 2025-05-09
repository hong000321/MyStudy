#include <stdio.h>

int main(void) {
	int num1 = 3, num2 = 4;
	double divResult;

	divResult = num1 / num2; //우측이 선 처리 된 후 그 결과 값(0) 이 좌측 divResult에 대입됨으로 결과는 0.0으로 나옴
	printf("나눗셈 결과: %f \n", divResult);

	return 0;
}