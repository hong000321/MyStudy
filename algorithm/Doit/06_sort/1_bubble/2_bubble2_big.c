#include <stdio.h>
#include <stdlib.h>

#define swap(type,x,y) do {type t = x; x=y; y=t; } while(0)

void bubble(int a[], int n){
    int i,j;
    for(i=0; i<n-1 ; i++){
        for(j=0; j<n-1-i; j++){ // 패스 : 큰 값부터 결정 되도록 조건 수정
            if(a[j]>a[j+1])
                swap(int, a[j], a[j+1]);
        }
    }
}


int main(void){

    int i, nx;
    int *x;

    puts("버블 정렬");
    printf("요소 개수: ");
    scanf("%d",&nx);

    x = (int *)calloc(nx, sizeof(int));

    for(i=0; i<nx ; i++){
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    bubble(x,nx);

    puts("오름차순으로 정렬했습니다.");
    for(i=0; i<nx; i++){
        printf("x[%d] = %d\n",i, x[i]);
    }
    free(x);
    return 0;
}