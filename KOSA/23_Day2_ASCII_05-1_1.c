#include <stdio.h>
#include "Test_header.h"

#if FILE_NUM == 23
int my_main(void) {
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	int x_w = 0, y_w = 0;
	int area = 0;
	printf("좌 상단의 x, y 좌표:");
	scanf("%d %d", &x1, &y1);
	printf("우 하단의 x, y 좌표:");
	scanf("%d %d", &x2, &y2);

	x_w = x2 - x1;
	y_w = y1 - y2;

	if (x_w < 0) x_w = -x_w;
	if (y_w < 0) y_w = -y_w;


	printf("두 점이 이루는 직사각형의 넓이는 %d 입니다.", x_w * y_w);

	return 0;
}
#endif