#include <stdio.h>

int main(void) {
    int n = 0;
    int index = 1;
    scanf("%d",&n);
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<n ; j++){
            printf("%d ",index);
            index++;
        }
        printf("\n");
    }
	
	return 0;
}
