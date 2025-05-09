#include <iostream>

int foo(){
    int i,j;
    j=i+2;
    return j;
}

int main(){
    for(int i=0; i<10 ; i++){
        printf("Result #%d : %d\n",i,foo());
    }
    return 0;
}