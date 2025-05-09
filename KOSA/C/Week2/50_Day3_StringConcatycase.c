#include <stdio.h>
#include <string.h>

int main(void){
    char str1[20]="First~";
    char str1[20]="First~";
    
    char str3[20]="Simple num: ";
    char str4[20]="1234567890";

    /**** case 1 *** */
    strcpy(str1, str2);
    puts(str1);

    /**** case 2 *** */
    strncpy(str3, str4, 7);
    puts(str3);


    return 0;    

}