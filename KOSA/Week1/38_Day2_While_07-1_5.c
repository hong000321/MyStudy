#include <stdio.h>

int main(void) {
	double sum = 0;
	int input_num = 0;
	int tmp_num = 0;
	int tmp_loop = 0;

	printf("입력할 수 입력 : \n");
	scanf("%d", &input_num);

	while ((input_num != tmp_loop)) {
		tmp_loop++;
		scanf("%d", &tmp_num);
		sum += tmp_num;
	}

	printf("result = %f\n", sum/input_num);
	return 0;
}