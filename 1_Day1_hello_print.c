#include <stdio.h>						// stdio.h ��� ���� ����
#include "Test_header.h"				// my_main() �Լ��� ���� �� ������ �����ϴ� ��� ȣ��

#if FILE_NUM == 1						// FILE_NUM�� �����Ͽ� �ش� ������ �´ٸ� �Ʒ� �ڵ� ����
int my_main(void) {						// my_main() �Լ� ȣ��
	printf_s("Hello, World! \n");		// �͹̳ο��� ���� �� Hello, World! ���
	return 0;							// 0�� my_main ������ ��ȯ
}
#endif