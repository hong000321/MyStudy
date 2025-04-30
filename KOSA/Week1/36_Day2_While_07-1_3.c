#include <stdio.h>

int main(void) {
	int input = 0;
	int result = 0;

	while (1) {
		scanf("%d", &input);
		if (input == 0) {
			break;
		}

		result += input;
	}

	printf("%d", result);
	return 0;
}