#include <stdio.h>

int main(void) {
	float f = 0.0F;
	int i = 0;
	for (f = 0.0; f < 100;f += 0.1f, i++) {
		printf("f: %f\n", f);
	}
	printf("i:%d\n", i);
	return 0;

}