#include <stdio.h>

int main(void){
    char arr_a[BUFSIZ] = "";
    int n = 0;
    scanf("%s",arr_a);
    char ascii_null = '\0';
    int i = 0;
    while(1){
        if(arr_a[i] == ascii_null){
            break;
        }
        i++;
    }
    printf("num = %d ",i);
    int ok = 1;
    for(int j = 0; j<i/2 ; j++){
        if(arr_a[j] == arr_a[i-j-1]){
            ok &= 1;
        }else{
            ok &= 0;
        }
    }

    if(ok) 
        printf("\nok");
    
    return 0;
}