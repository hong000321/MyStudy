#include <stdio.h>
#include <math.h>


void findC(int n, int arr[], int *gcd, int *lcm){
    int tmp_gd = arr[0];
    int tmp_lm = arr[0];
    for(int i = 1 ; i<n ; i++){
        tmp_gd = findGCD(tmp_gd, arr[i]);
    }
    *gcd = tmp_gd;
    tmp_gd = arr[0];
    tmp_lm = arr[0];
    for(int i = 1 ; i<n ; i++){
        tmp_gd = findGCD(tmp_lm, arr[i]);
        tmp_lm = tmp_lm*arr[i]/tmp_gd;
    }
    *lcm = tmp_lm;
}


int main(void){
    int num;
    int arr[10];
    scanf("%d",&num);
    for(int i = 0; i<num ; i++){
        scanf("%d",&arr[i]);
    }
    
    int gcd = 0;
    int lcm = 0;
    findC(num, arr,&gcd, &lcm);
    
    printf("%d ",gcd);
    printf("%d",lcm);

    // printf("gcd = %d\n",gcd);
    // printf("lcm = %d",lcm);

    return 0;
}