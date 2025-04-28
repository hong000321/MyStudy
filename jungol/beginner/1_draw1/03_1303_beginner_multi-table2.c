#include <stdio.h>

int main(void) {
	int val1 = 0;
	int val2 = 0;

	while(1){
		scanf("%d %d", &val1, &val2);
		if ((val1 < 2) || (val1 > 9) || (val2 < 2) || (val2 > 9)) {
			printf("INPUT ERROR!");
			continue;
		}

        if(val1<val2){    
            for(int i=val1; i<val2+1; i++){
                for(int j=1; j<10; j++){
                    printf("%d * %d = %2d   ",i,j,i*j);
                    if((j%3)==0) printf("\n");
                }
                printf("\n");
            }
        }else{
            for(int i=val1; i>val2-1; i--){
                for(int j=1; j<10; j++){
                    printf("%d * %d = %2d   ",i,j,i*j);
                    if((j%3)==0) printf("\n");
                }
                printf("\n");
            }
        }
		break;
	}
	
	return 0;
}
