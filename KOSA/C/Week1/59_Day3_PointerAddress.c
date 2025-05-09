#include <stdio.h>

int main(void)
{
	int num1 = 100, num2 = 100;
	int *pnum;
	pnum = &num1;
	(*pnum) += 30;

	printf("Address of num1 : %p\n", &num1);
	printf("value of pnum : %p\n", pnum);
	printf("Address of pnum : %p\n", &pnum);

	pnum = &num2;
	(*pnum) += 30;

	printf("Address of num2 : %p\n", &num2);
	printf("value of pnum : %p\n", pnum);
	printf("Address of pnum : %p\n", &pnum);
	printf("num1 : %d, num2 : %d\n", num1, num2);

	return 0;
}