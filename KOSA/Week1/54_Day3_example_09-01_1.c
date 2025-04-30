#include <stdio.h>

#include "Test_header.h"

#if FILE_NUM == 54

int getMax(int num1, int num2, int num3);

int getMin(int num1, int num2, int num3);

int my_main(void)

{

    int num1, num2, num3;

    scanf("%d %d %d", &num1, &num2, &num3);

    printf("%d, %d, %d --> max: %d\n",

        num1, num2, num3,

        getMax(num1, num2, num3));

    printf("%d, %d, %d --> min: %d\n",

        num1, num2, num3,

        getMin(num1, num2, num3));

    return 0;

}

int getMax(int num1, int num2, int num3)

{

    int max;

    max = (num1 > num2) ? num1 : num2;

    max = (max > num3) ? max : num3;

    return max;

}

int getMin(int num1, int num2, int num3)

{

    int min;

    min = (num1 < num2) ? num1 : num2;

    min = (min < num3) ? min : num3;

    return min;

}

#endif
