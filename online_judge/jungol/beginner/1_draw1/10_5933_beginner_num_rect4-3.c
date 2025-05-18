#include <stdio.h>

int main(void) {
    int n = 0;

    scanf("%d",&n);
    for(int i = 0 ; i<n ; i++){
        for(int j = 1 ; j<n+1 ; j++){
            printf("%d ",j*(i+1));
        }
        printf("\n");
    }
	
	return 0;
}
