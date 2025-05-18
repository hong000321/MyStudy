#include <stdio.h>

int main(void) {
    int n = 0;

    scanf("%d",&n);
    for(int i = 1 ; i<n+1 ; i++){
        for(int j = 0 ; j<n ; j++){
            printf("%d ",j*n+i);
        }
        printf("\n");
    }
	
	return 0;
}
