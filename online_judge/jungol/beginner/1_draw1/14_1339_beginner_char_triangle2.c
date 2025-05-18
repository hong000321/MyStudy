#include <stdio.h>


int main(void){
    int n = 0;
    int k = 0;
    int u = 1;
    int m = 1;
    int ascii = 65;
    int array[100][100] = {0};
    scanf("%d",&n);

    if(n%2==0 || n>100){
        printf("INPUT ERROR\n");
        return 0;
    }
    k = n/2;
    for(int i = k; i>=0 ; i--){
        for(int j = k; j<k+u ; j++){
            array[j+i-k][i] = m;
            m++;
        }
        u+=2;
    }

    for(int i = 0; i<n ; i++){
        for(int j = 0 ; j<n ; j++){
            if(array[i][j] == 0)
                printf("  ");
            else
                printf("%c ",ascii+((array[i][j]-1)%26));
            
        }
        printf("\n");
    }


    return 0;
}