#include <stdio.h>
#include "Test_header.h"


#if FILE_NUM == 36
int my_main(void) {
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
#endif