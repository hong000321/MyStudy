#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void SplitNameAge(char arr[20], char (*name)[10], char (*age)[10]){
    int index=0;
    for(int i=0; i<20 ; i++){
        if(arr[i]==' '){
            index = i;
            break;
        }
    }
    printf("%d \n",index);
    strncpy(*name,arr,index);

    strcpy((*age),arr+index+1);
}

int main(void){
    char str1[20];
    char str2[20];

    char name[2][10]={0};
    char age[2][10]={0};

    gets(str1);
    gets(str2);

    SplitNameAge(str1,&(name[0]),&(age[0]));
    SplitNameAge(str2,&(name[1]),&(age[1]));

    printf("name: %s   age: %s\n",name[0], age[0]);
    printf("name: %s   age: %s\n",name[1], age[1]);

    printf("%d \n",strcmp(name[0],name[1]));
    printf("%d %d \n",strlen(name[0]),strlen(name[1]));
    
    if(!strcmp(name[0],name[1])){
        if(atoi(age[0])==atoi(age[1]))
            printf("이름과 나이가 같음\n");
        else
            printf("이름은 같은데 나이가 다름\n");
    }else{
        if(atoi(age[0])==atoi(age[1]))
            printf("이름은 다른데 나이가 같음\n");
        else
            printf("이름과 나이가 다름\n");
    }
    
    return 0;
}