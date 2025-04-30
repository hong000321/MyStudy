#include <stdio.h>


/**
 * C:\test> main_arg abcd 1234
 * argc = 3
 * argv = {"main_arg", "abcd", "1234"}
 */
int main(int argc, char **argv){
    int i=0;
    printf("전달된 문자열의 수: %d \n", argc);

    for(i=0; i<argc; i++){
        printf("%d번째 문자열: %s \n", i+1, argv[i]);
    }
    return 0;
}