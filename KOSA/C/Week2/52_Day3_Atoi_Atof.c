#include <stdio.h>
#include <stdlib.h>
/*
int atoi(char *ptr);
long atol(char *ptr);
double atof(char *str);
 */

int main(void){
    char ascii[100] = "1234.4939";
    
    printf("atoi : %d\n",atoi(ascii));
    printf("atol : %ld\n",atol(ascii));
    printf("atof : %lf\n",atof(ascii));
    return 0;
}