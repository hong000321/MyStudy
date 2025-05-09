#include <stdio.h>
#define TEST_STR "test"


int main(void){

    const char test[20]=TEST_STR;
    char *test1 = TEST_STR;
    char test2[20] = {'t','e','s','t','\0'};

    printf("test addr = %p\n",test);
    printf("test addr = %p\n",TEST_STR);
    printf("str  addr = %p",test1);
    return 0;

}