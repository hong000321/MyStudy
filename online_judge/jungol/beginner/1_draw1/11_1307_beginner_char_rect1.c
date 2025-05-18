#include <stdio.h>

int main(void) {
    int n = 0;
    int ascii_a = 65;
    int index = 0;
    scanf("%d",&n);
    for(int i = 1 ; i<n+1 ; i++){
        for(int j = n ; j>0 ; j--){
            index = j*n-i;
            printf("%c ",ascii_a+(index%26));
        }
        printf("\n");
    }
	
	return 0;
}
