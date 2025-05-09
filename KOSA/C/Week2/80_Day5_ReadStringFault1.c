#include <stdio.h>

void ReadUserName(char **name){
    printf("What's your name : ");
    fgets(*name,sizeof(*name),stdin);
}


int main(void){
    char *name1;
    char *name2;
    ReadUserName(&name1);
    ReadUserName(&name2);
    printf("name1: %s \n", name1);
    printf("name2: %s \n", name2);
    return 0;
}