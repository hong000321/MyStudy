
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MIN_N 1
#define MAX_N 5

char *flag;

void setFlag(int index, int value){
    if(value == 0){
        flag[index/4] &= ~(0x01 << (index%4));
    }else if(value == 1){
        flag[index/4] |= (0x01 << (index%4));
    }else{
        perror("unknown input flag!!");
    }
}

int isFlagTrue(int index){
    return (flag[index/4]) & (0x01 << (index%4)) ;
}


int main(void){
    flag = (char *)calloc((MAX_N/4)+1,sizeof(char));
    memset(flag,0xFF,(MAX_N/4)+1);
    setFlag(3,0);

    for(int i=0; i<MAX_N; i++){
        int ret = 0;
        if(isFlagTrue(i)){
            ret = 1;
        }
        printf("%d",ret);
    }
    int a;
    scanf("%d",&a);
    return 0;
}