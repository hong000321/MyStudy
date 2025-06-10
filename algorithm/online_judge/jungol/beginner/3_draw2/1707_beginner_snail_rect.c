#include <stdio.h>
#include <stdlib.h>


void solver11(int n){
    int w = n;
    int h = n;
    int i,j;
    int index_w=-1, index_h=0;
    int val=0;
    int **a;
    a = (int**)calloc(n,sizeof(int*));
    for(i=0;i<n;i++){
        a[i] = (int*)calloc(n,sizeof(int));
    }

    for(i=0;i<n;i++){
        for(j=0;j<w;j++){
            index_w+=(i%2==0)?1:-1;
            a[index_h][index_w] = ++val;   
        }
        //index_w-=(i%2==0)?1:-1;
        h--;
        if(i!=n-1){
            for(j=0;j<h;j++){
                index_h+=(i%2==0)?1:-1;
                a[index_h][index_w] = ++val;
            }
            // index_h-=(i%2==0)?1:-1;
            w--;
        }
    }
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    fflush(stdout);
    for(i=0;i<n;i++){
        free(a[i]);
    }
    free(a);
}

int main(void){
    int n;
    scanf("%d", &n);

    solver11(n);


    return 0;
}