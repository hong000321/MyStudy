#include <stdio.h>
#include "Test_header.h"


#if FILE_NUM == 37
int my_main(void) {
	int input = 0;
	int num = 9;
	scanf("%d", &input);
	while (num--) {  // 후위 연산자지만 printf를 실행 할 시점에는 이미 연산이 끝난 시점이기 때문에 
		printf("%d * %d = %d \n", input, num+1, input * (num+1));  // 1을 더해줌
	}
	return 0;
}
#endif