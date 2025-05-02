#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct twoshort{
    unsigned short up;
    unsigned short dn;
}TwoShort;

typedef union buf{
    int ibuf;
    char cbuf[4];
    TwoShort sbuf;
}Buf;

int main(void){
    Buf abuf;
    abuf.ibuf = 1145258561;//(0100 0100) (0100 0011) (0100 0010) (0100 0001) = 68 67 66 65 = D C B A
    //scanf("%d",&abuf.ibuf); 
    printf("up = %d  dn = %d\n",abuf.sbuf.up, abuf.sbuf.dn);
    for(int i=0; i<4; i++){
        printf("char%c = %c(%d) \n",i+1,abuf.cbuf[i],abuf.cbuf[i]); // 실제 출력은 A B C D -> 하위바이트 먼저 저장됨 -> little endian
    }

    return 0;
}