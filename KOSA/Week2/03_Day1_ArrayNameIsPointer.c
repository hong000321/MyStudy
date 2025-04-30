#include <stdio.h>
#include "Test_header.h"


#if FILE_NUM == 62
int my_main(void) {
	int arr[3] = { 15,25,35 };
	int* ptr = &arr[0];

	printf("%d %d \n", ptr[0], arr[0]);
	printf("%d %d \n", ptr[1], arr[1]);
	printf("%d %d \n", ptr[2], arr[2]);
	printf("%d %d \n", *ptr, *arr);

	return 0;
}
#endif