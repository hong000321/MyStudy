#include <stdio.h>

int main(void) {
	int input = 0;
	int tmp_num = 0;
	scanf("%d", &input);

	while (input--) {
		tmp_num += 3;
		printf("%d ", tmp_num);
	}

	return 0;
}