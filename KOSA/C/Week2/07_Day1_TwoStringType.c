#include <stdio.h>

int main(void) {
	char str1[] = "My string";
	char* str2 = "Your String";
	printf("%s %s \n", str1, str2);

	str1[0] = 'X';
	str2[0] = 'X';
	printf("%s %s \n", str1, str2);

	return 0;
}