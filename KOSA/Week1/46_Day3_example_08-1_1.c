#include <stdio.h>

#include "Test_header.h"

#if FILE_NUM == 46

int my_main(void) {

	int limit = 100;

	int count = 1;

	while (count<limit) {

		if (!((count % 7) && (count % 9))) {

			printf("%d\n", count);

		}

		count++;

	}

	return 0;

}

#endif