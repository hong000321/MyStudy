#include <stdio.h>

int main(void) {
	int i = 0, j = 0;
	int num = 0;
	while (i < 10) {
		while (j < 10) {
			num++;
			j++;
		}
		i++;
		j = 0;
	}

	printf("i = %d, j = %d , num = %d\n", i, j, num);
	return 0;
}