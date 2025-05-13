#include <stdio.h>
#include <stdlib.h>

void fsort(int a[], int n, int max){
    int i;
    int *f = (int*)calloc(max + 1, sizeof(int));      //1-1
    int *b = (int*)calloc(n, sizeof(int));            //3-1

    for(i=0; i<=max; i++) f[i]=0;               //1-1 : 0으로 초기화
    for(i=0; i<n; i++) f[a[i]]++;               //1-2 : 배열 a의 요소 값에 맞는 도수분포표 만들기
    for(i=1; i<=max; i++) f[i] += f[i-1];       //2-1 : 도수분포표를 누적도수분포표로 만들기
    for(i= n-1; i>=0; i--) b[--f[a[i]]] = a[i]; //3   : 배열 a의 위치를 배열 a에서 참고하여 배열 b에 저장하기
    for(i=0; i<n; i++) a[i] = b[i];             //4   : 배열 b,f는 임시배열 이므로 배열 a에 배열 b값을 복사하기.

    free(b);
    free(f);
}


int main(void){
    int i, nx;
    int *x;
    const int max = 100;
    puts("도수 정렬");
    printf("요소 개수 : ");

    scanf("%d", &nx);
    x = (int*)calloc(nx, sizeof(int));
    printf("0 ~ %d의 정수를 입력하세요.\n",max);

    for(i=0; i<nx; i++){
        do{
            printf("x[5d] : ",i);
            scanf("%d", &x[i]);
        } while(x[i] < 0 || x[i] > max);
    }
    fsort(x,nx,max);
    
    puts("오름차순으로 정렬했습니다.");
    for(i=0; i<nx; i++){
        printf("x[%d] = %d\n",i, x[i]);
    }
    free(x);

    return 0;
}