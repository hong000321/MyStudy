#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

int main(void)
{
	printf("char : %lu\n", sizeof(int8_t));
	printf("short : %lu\n", sizeof(int16_t));
	printf("int : %lu\n", sizeof(int32_t));
	printf("long : %lu\n", sizeof(int64_t));
	printf("float : %lu\n", sizeof(float));
	printf("double : %lu\n", sizeof(double));

	return 0;
}