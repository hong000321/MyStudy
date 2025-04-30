#include <stdio.h>


int main(void){
    int diff = 'a' - 'A';
    while(1){
        int alp = getchar();
        if(alp<='z' && alp>='a'){
            putchar(alp-diff);
        }else if(alp<='Z' && alp>='A'){
            putchar(alp+diff);
        }else if(alp == 10){
            printf("\n");
        }else{
            printf("INPUT ERROR!, %d",alp);
        }
    }

    return 0;

}