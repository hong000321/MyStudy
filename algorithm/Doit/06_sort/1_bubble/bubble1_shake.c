#include <stdio.h>
#include <stdlib.h>

#define swap(type,x,y) do {type t = x; x=y; y=t; } while(0)


void bubble(int a[], int n){
    int i,j;
    int alpha=0,beta=0;
    for(i=0; i<n-1 ; i++){
        if(i%2==0){
            for(j=n-1-beta; j>alpha; j--){ // 패스 (작은 값 정렬)
                if(a[j-1]>a[j])
                    swap(int, a[j-1], a[j]);
            }
            alpha++;
        }else{
            for(j=alpha; j<n-1-beta; j++){ // 패스(큰 값 정렬)
                if(a[j]>a[j+1])
                    swap(int, a[j], a[j+1]);
            }
            beta++;
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