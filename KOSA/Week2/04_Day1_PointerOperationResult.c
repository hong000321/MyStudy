#include <stdio.h>
#include "Test_header.h"


#if FILE_NUM == 63
int my_main(void) {
	int* ptr1 = 0x0010;
	double* ptr2 = 0x0010;

	printf("%p %p \n", ptr1 + 1, ptr1 + 2);
	printf("%p %p \n", ptr2 + 1, ptr2 + 2);

	printf("%p %p \n", ptr1, ptr2);

	ptr1++;
	ptr2++;
		
	printf("%p %p \n", ptr1, ptr2);

	return 0;
}
#endif