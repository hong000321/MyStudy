#include <stdio.h>
#include <stdlib.h>
int main(void){
    char *str;
    char *out;
    int size = 0;

    scanf("%d%*c",&size);

    str = (char *)malloc(size*sizeof(char)+1);
    out = (char *)malloc(size*sizeof(char)+1);
    fgets(str,size+1,stdin);
    printf("%s\n",str);
    int index1 = 0;
    int index2 = 0;
    char *tmp_addr1;
    char *tmp_addr2;
    for(int i = 0 ; i<size ; i++){
        *(out+i)=' ';
    }
    *(out+size)='\0';
    while(size>=index2){
        printf("size = %d , index2 = %d, char = %d\n",size, index2,*(str+index2));
        if(*(str+index2)==' ' || *(str+index2)=='\0'){
            printf("\nindex1 = %d , index2 = %d\n",index1, index2);
            for(int i=0; i<(index2-index1); i++){
                tmp_addr1 = out+(size-index2+i);
                tmp_addr2 = str+(index1+i);
                *(tmp_addr1) = *(tmp_addr2);
            }
            index1 = index2+1;
        }
        index2++;
    }
    *(out+size)='\0';


    printf("result : %s\n",out);
    free(str);
    free(out);

    return 0;
}