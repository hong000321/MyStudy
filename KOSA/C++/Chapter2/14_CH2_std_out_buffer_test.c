#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void){
    char buf[BUFSIZ];
    buf[0] = '\0';

    for(int i=1; i<10; i++){
        char str[4];
        sprintf(str,"%d ",i);
        strcat_s(buf,sizeof(str),str);
    }
    buf[BUFSIZ-1] = '\0';

    printf("%s",buf);


    return 0;
}