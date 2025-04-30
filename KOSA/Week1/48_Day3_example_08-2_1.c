#include <stdio.h>
int main(void) {
	for (int i = 1; i < 10; i++) {
		if (i % 2 == 1) {
			continue;
		}
		else {
			for (int j = 1; j < i + 3; j++) {
				printf("%d x %d = %d \n", i, j, i * j);
			}
			printf("\n");
		}
	}
	return 0;
}