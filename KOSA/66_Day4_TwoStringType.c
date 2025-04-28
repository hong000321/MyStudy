#include <stdio.h>
#include "Test_header.h"


#if FILE_NUM == 66
int my_main(void) {
	char str1[] = "My string";
	char* str2 = "Your String";
	printf("%s %s \n", str1, str2);

	str1[0] = 'X';
	str2[0] = 'X';
	printf("%s %s \n", str1, str2);

	return 0;
}
#endif