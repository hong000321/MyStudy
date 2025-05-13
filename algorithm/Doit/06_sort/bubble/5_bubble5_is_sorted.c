#include <stdio.h>
#include <stdlib.h>

#define swap(type,x,y) do {type t = x; x=y; y=t; } while(0)

int is_sorted(int a[], int n){
    int i,j;
    int exch_n;
    for(j=n-1; j>0; j--){ // 패스
        if(a[j-1]>a[j]){
            swap(int, a[j-1], a[j]);
            exch_n++;
        }
    }
    if(exch_n == 0)
        return 1;
    return 0;
}


int main(void){

    int i, nx;
    int *x;
    int ret = 0;
    puts("버블 정렬");
    printf("요소 개수: ");
    scanf("%d",&nx);

    x = (int *)calloc(nx, sizeof(int));

    for(i=0; i<nx ; i++){
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    ret = is_sorted(x,nx);

    for(i=0; i<nx; i++){
        printf("x[%d] = %d\n",i, x[i]);
    }
    printf("졍렬 %s",ret?"됨":"안됨");
    free(x);
    return 0;
}