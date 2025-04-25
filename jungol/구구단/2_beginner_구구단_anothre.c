#include <stdio.h>
#include "Test_header.h"


#if FILE_NUM == 2

struct Input {
	int s;
	int e;
};
struct Input scan() {
	struct Input form;
	scanf("%d %d", &form.s, &form.e);
	if(form.s < 2 || form.s > 9 || form.e < 2 || form.e > 9) {
		puts("INPUT ERROR!");
		return scan();
	}
	return form;
}
int my_main() {
	struct Input input = scan();
	for(int i = 1; i <= 9; i++) {
		if(input.s < input.e) {
            for(int j = input.s; j <= input.e; j++) {
                printf("%d * %d = %2d   ", j, i, j * i);
            }
        }
		else {
            for(int j = input.s; j >= input.e; j--) {
                printf("%d * %d = %2d   ", j, i, j * i);
            }
        }
		puts("");
	}
	return 0;
}
#endif