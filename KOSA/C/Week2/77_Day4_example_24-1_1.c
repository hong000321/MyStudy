#include <stdio.h>

typedef struct people
{
    char *name;
    char *id;
    char *phone;
    char *food[3];
    char *hob[3];
}People;

void WritePeople(People p, FILE *fd){
    fputs("\n#이름: ",fd);
    fputs(p.name,fd);
    fputs("\n#주민번호: ",fd);
    fputs(p.id,fd);
    fputs("\n#전화번호: ",fd);
    fputs(p.phone,fd);
    fputs("\n#즐겨먹는 음식: ",fd);
    fputs(p.food[0],fd);
    fputs("\n#취미: ",fd);
    fputs(p.hob[0],fd);
}

void PrintFile(FILE *fd){
    char str[10];
    
    while(fgets(str,sizeof(str),fd)!=NULL){
        printf("%s",str);
    }
}

int main(void)
{
    FILE *dest=fopen("dest.txt", "wt");
    People p;
    p.name = "윤성우";
    p.id = "900208-1012589";
    p.phone = "010-1111-2222";
    p.food[0] = "짬뽕";
    p.food[1] = "탕수육";
    p.hob[0] = "축구";

    if(dest==NULL){
        puts("파일오픈 실패!");
        return -1;
    }
    int a = 11;
    

    WritePeople(p,dest);

    fclose(dest);


    dest=fopen("dest.txt", "rt");
    PrintFile(dest);
    fclose(dest);
    return 0;

}