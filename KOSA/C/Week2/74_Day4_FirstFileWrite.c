#include <stdio.h>
typedef FILE* FILEPTR;
int main(void)
{
    FILEPTR fp=fopen("data.txt","wt");
    if(fp == NULL){
        puts("파일오픈 실패!");
        return -1;
    }
    fputc('A',fp);
    fputc('b',fp);
    fputc('C',fp);
    int b=11;
    int a=b;
    fprintf(fp,"%d",a);
    fclose(fp);
    return 0;

}