#include <stdio.h>

void print10to2(int a){
    int ptr = 0x80000000;
    for(int i = 0 ; i<32 ; i++){
        if((a<<i)&(ptr))
            printf("1");
        else{
            printf("0");
        }
    }
}
int main(void){
    int a = 0;
    scanf("%d",&a);
    print10to2(a);
    
    return 0;
}