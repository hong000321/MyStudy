#include <stdio.h>

int main(void) {
    int n = 0;

    scanf("%d",&n);
    for(int i = 0 ; i<n ; i++){
        for(int j = 1 ; j<n+1 ; j++){
            if((i&0x01) == 1){ //짝수 줄
                printf("%d ",n-j+1);
            }else{ // 홀수 줄
                printf("%d ",j);
            }
        }
        printf("\n");
    }
	
	return 0;
}
