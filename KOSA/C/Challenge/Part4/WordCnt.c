#include <stdio.h>

int UseScanf(FILE *fp, int *a_cnt, int *p_cnt){
    while(!feof(fp)){
        char tmp[100] = {'\0'};
        fscanf(fp,"%s",tmp);
        if(tmp[0] == 'A' || tmp[0] == 'a')
            (*a_cnt)++;
        if(tmp[0] == 'p' || tmp[0] == 'P')
            (*p_cnt)++;
    }
    return 0;
}

void UseGetc(FILE *fp, int *a_cnt, int *p_cnt){
    while(!feof(fp)){
        char ch = '\0';
        ch = fgetc(fp);
        if(ch == ' '){
            ch = fgetc(fp);
            if(ch == 'A' || ch == 'a'){
                (*a_cnt)++;
            }
            if(ch == 'p' || ch == 'P')
                (*p_cnt)++;
        }
    }
} 

int main(int argc, char **argv){
    int a_cnt=0, p_cnt=0;
    FILE *fp;

    if(argc < 1){
        fprintf(stderr, "Usage : %s filename\n", argv[0]);
        return -1;
    }
    fp = fopen(argv[1], "rt");
    UseScanf(fp,&a_cnt,&p_cnt);
    printf("scanf  A: %d       P: %d\n",a_cnt,p_cnt);
    a_cnt = 0;
    p_cnt = 0;
    fseek(fp,0, SEEK_SET);
    UseGetc(fp,&a_cnt,&p_cnt);
    printf("getc   A: %d       P: %d",a_cnt,p_cnt);
    fclose(fp);
    return 0;
}