#include <stdio.h>
#include <stdlib.h>

#define swap(type,x,y) do {type t = x; x=y; y=t; } while(0)

void bubble(int a[], int n){
    int p_i,r_i;        // pass index , right value index
    int swap_flag = 0;  // 각 패스에서 스왑이 발생하면 1, 아니면 0
    int comp_n = 0;     // 비교 발생 시 +1
    int chng_n = 0;     // 교환 발생 시 +1
    for(p_i=0; p_i<n-1 ; p_i++){        // 패스 n-1번 실행하기 위한 루프
        printf("패스%d :\n",p_i+1);
        for(r_i=n-1; r_i>p_i; r_i--){   // 패스 내부에서 배열의 두 요소를 비교 및 교환하기 위한 루프
            comp_n++;                   // 비교 ++
            if(a[r_i-1]>a[r_i]){        // 우측(r_i) 좌측(r_i-1) 비교
                chng_n++;               // 스왑 ++
                swap_flag = 1;          // 스왑 플래그 1로 설정
                swap(int, a[r_i-1], a[r_i]);  // 스왑
            }else{                      // 스왑 X
                swap_flag = 0;          // 스왑 플래그 0으로 설정
            }
            for(int k=0; k<n; k++){     // 위에서 진행 된 두 요소 비교의 로그를 찍기 위한 루프
                printf("%d ",a[k]);     // 배열 값 출력
                if(r_i-1==k){           // 위에서 진행 된 두 요소 중 왼쪽 값 찾기
                    printf("%c ",swap_flag?'+':'-');    // 스왑시 + 아니면 -
                }else{
                    printf("  ");
                }
            }
            printf("\n");
        }
    }
    for(int k=0; k<n; k++){
        printf("%d   ",a[k]);
    }
    printf("\n비교를 %3d회 했습니다.\n",comp_n);
    printf("교환을 %3d회 했습니다.\n",chng_n);
    printf("\n");
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