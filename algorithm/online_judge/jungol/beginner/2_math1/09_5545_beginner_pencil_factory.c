#include <stdio.h>
#include <math.h>

int findGCD(int a, int b){
    int gcd;
    for(int i = 1 ; i<=a ; i++){
        if(a%i==0 && b%i==0){
            gcd = i;
        }
    }
    return gcd;
}

int findLCM(int a, int b){
    int lcm;
    int gcd = findGCD(a,b);
    lcm = a/gcd*b;
        return lcm;
}


int main(void){
    int p,v,k;
    int a,b,c,d;
    int arr[10];
    scanf("%d %d %d",&p,&v,&k);
    


    long lcm = findLCM(p+1,v+1);
    b = k/lcm;
    c = k/(v+1)-b;
    d = k/(p+1)-b;
    a = k - b - c - d;
    printf("%d %d %d %d",a,b,c,d);

    return 0;
}