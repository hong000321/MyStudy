#include <stdio.h>
#include "Test_header.h"

#if FILE_NUM == 23
int my_main(void) {
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	int x_w = 0, y_w = 0;
	int area = 0;
	printf("�� ����� x, y ��ǥ:");
	scanf("%d %d", &x1, &y1);
	printf("�� �ϴ��� x, y ��ǥ:");
	scanf("%d %d", &x2, &y2);

	x_w = x2 - x1;
	y_w = y1 - y2;

	if (x_w < 0) x_w = -x_w;
	if (y_w < 0) y_w = -y_w;


	printf("�� ���� �̷�� ���簢���� ���̴� %d �Դϴ�.", x_w * y_w);

	return 0;
}
#endif