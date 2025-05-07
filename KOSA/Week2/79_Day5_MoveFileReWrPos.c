#include <stdio.h>


int main(void){
    FILE *fp=fopen("text.txt", "wt");
    int add[3] = {0};
    fputs("123456789",fp);
    fclose(fp);

    fp=fopen("text.txt", "rt");
    add[0] = fseek(fp, -2, SEEK_END);
    putchar(fgetc(fp));

    add[1] = fseek(fp, 2, SEEK_SET);
    putchar(fgetc(fp));
    
    add[2] = fseek(fp, 2, SEEK_CUR);
    putchar(fgetc(fp));
    printf("\n");
    printf("%d \n",add[0] );
    printf("%d \n",add[1] );
    printf("%d \n",add[2] );
    return 0;
}