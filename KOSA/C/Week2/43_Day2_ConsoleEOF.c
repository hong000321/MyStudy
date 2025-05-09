#include <stdio.h>


int main(void){
    int ch;

    while(1){
        ch = getchar();
        if(ch==EOF)// EOF -> ctrl + z
            break;
        putchar(ch);
    }
    printf("end");
    return 0;

}