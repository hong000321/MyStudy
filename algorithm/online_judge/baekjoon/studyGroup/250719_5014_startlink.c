#include <stdio.h>

#define IS_NUM_OK(x,a,b) (x<a||x>b)?0:1

int my_solver(int F, int S, int G, int U, int D){
    int result = 0;

    if((U-D)>0){
        for(int i=0; i<)
    }
}


int main(void){
    int F, S, G, U, D;
    scanf("%d %d %d %d %d",&F, &S, &G, &U, &D);
    if(IS_NUM_OK(S,1,1000000)||IS_NUM_OK(G,1,1000000)){
        return -1;
    }

    if(IS_NUM_OK(F,S,1000000)||IS_NUM_OK(F,G,1000000)){
        return -1;
    }

    if(IS_NUM_OK(U,0,1000000)||IS_NUM_OK(D,0,1000000)){
        return -1;
    }



    my_solver(F,S,G,U,D);

    return 0;
}