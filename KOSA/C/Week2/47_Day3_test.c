#include <stdio.h>


int main(int argc, char *argv[]){
    int i;
    float f;
    char c, str[32];

    scanf("%d",&i); printf("1:%d\n",i);
    scanf("%f",&f); printf("2:%f\n",f);
    scanf("%*c%c",&c); printf("3:%c\n",c);
    scanf("%s",str); printf("4:%s\n",str);

    return 0;
}