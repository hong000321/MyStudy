#include <stdio.h>
#include "Test_header.h"


#if FILE_NUM == 37
int my_main(void) {
	int input = 0;
	int num = 9;
	scanf("%d", &input);
	while (num--) {  // ���� ���������� printf�� ���� �� �������� �̹� ������ ���� �����̱� ������ 
		printf("%d * %d = %d \n", input, num+1, input * (num+1));  // 1�� ������
	}
	return 0;
}
#endif