#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void){
    char arr[100];
    int i = 0;
    int result = 0;
    gets(arr);
    for(int i = 0; i<strlen(arr) ; i++){
        if(arr[i]<='9' && arr[i]>='0'){
            result += arr[i]-48;
            printf("%d ",arr[i]-48);
        }
    }
    printf("\n%d ",result);
    return 0;
}