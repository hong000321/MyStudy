#include <stdio.h>
#include <stdlib.h>

typedef struct library_data{
    char author[30];
    char title[30];
    int page;
}Library_d;

void AddBook(Library_d *l, int index){
    printf("도서 정보 입력\n저자: ");
    scanf("%s",l[index].author);

    printf("제목: ");
    scanf("%s",l[index].title);

    printf("페이지 수: ");
    scanf("%d",&l[index].page);
    printf("\n");
}

void PrintBook(Library_d *l, int index){
    printf("\nbook %d\n",index+1);
    printf("저자 : %s\n",l[index].author);
    printf("제목 : %s\n",l[index].title);
    printf("페이지 수 : %d\n\n",l[index].page);
}

int main(void){
    int size = 3;
    Library_d *l_data;
    l_data = (Library_d *)calloc(size,sizeof(Library_d));
    if(l_data==NULL){
        return -1;
    }
    for(int i = 0; i<3 ; i++){
        AddBook(l_data,i);
    }

    for(int i = 0; i<3 ; i++){
        PrintBook(l_data,i);
    }
    if(l_data != NULL){
        free(l_data);
    }
    return 0;
}