#include <stdio.h>
#include <string.h>

int main(void){
    char str1[20];
    char str2[20];
    char str3[40];

    fgets(str1,20,stdin);
    fgets(str2,20,stdin);

    strncpy(str3,str1,strlen(str1)-1);
    strncpy(str3+strlen(str1)-1,str2,strlen(str2));

    printf("%s\n",str3);
    
    return 0;
}