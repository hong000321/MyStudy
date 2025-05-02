#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct sbox1
{
    int mem1;
    double mem2;
    char mem3;
}SBox1;

typedef struct sbox2
{
    int mem1;
    char mem2;
    double mem3;
}SBox2;

typedef struct sbox3
{
    char mem1;
    int mem2;
    double mem3;
}SBox3;

typedef union ubox
{
    int mem1;
    int mem2;
    double mem3;
}UBox;


int main(void){
    SBox1 sbx;    
    UBox ubx;

    printf("%d %d %d | %d\n",sizeof(SBox1),sizeof(SBox2),sizeof(SBox3),sizeof(UBox));
    return 0;
}