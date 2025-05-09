#include <stdio.h>


int main(void){
    int ch1, ch2;

    ch1=getchar();
    ch2=fgetc(stdin);

    putchar(ch1+1);
    fputc(ch2+30, stdout);
    

    return 0;

}