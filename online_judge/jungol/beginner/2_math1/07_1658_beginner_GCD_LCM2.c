#include <stdio.h>
#include <math.h>
#include <sys/time.h>

long getMicrotime(){
	struct timeval currentTime;
	gettimeofday(&currentTime, NULL);
	return currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;
}

int numCheck(int n, int a, int b){
    if(n<a || n>b){
        return 0;
    }
    return 1;
}


int findGCD(int x, int y){
    int i, ans;
    for (i = 1; i<= x; i++){
        if(x%i==0 && y%i==0){
            ans = i;
        }
    }
    return ans;
}

int main(void){
    long start, end; 
    double time;
    int n1 = 0;
    int n2 = 0;
    scanf("%d %d" , &n1, &n2);
    start = getMicrotime(); // 수행 시간 측정 시작
    if(!numCheck(n1,1,10000) || !numCheck(n2,1,10000)){
        printf("INPUT ERROR!");
        return 0;
    }


    int gcd = findGCD(n1,n2);
    int lcm = n1*n2/gcd;
    printf("%d\n%d\n",gcd,lcm);
    //printf("gcd = %d \nlcm = %d\n",gcd,lcm);
    
    
    end = getMicrotime(); //시간 측정 끝
    time = (double)(end - start);
    //printf("%lf ms\n",time/1000);
    return 0;
}