#include "str.h"


int main(void){
    StringCharArray customString = "Hello, World!";


    char out[20];
    customString.toCharArray(out);

    printf("output = %s",out);


    return 0;
}