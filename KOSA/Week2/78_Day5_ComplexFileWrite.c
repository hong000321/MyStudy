#include <stdio.h>

int main(void){
    char name[10];
    char sex;
    int age;

    FILE *fp=fopen("friend.txt", "wt");
    int i;
    char c;
    for(i=0; i<3; i++){
        printf("{이름 성별 나이} 순 입력: ");
        scanf("%c %s %c %d", &c, name, &sex, &age);
        // c = getchar();
        printf("%d\n",c);
        fprintf(fp, "\n%s %c %d", name, sex, age);
    }
    fclose(fp);

    return 0;
}
