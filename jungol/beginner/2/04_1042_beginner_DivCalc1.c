#include <stdio.h>
#include <sys/time.h>

long getMicrotime(){
	struct timeval currentTime;
	gettimeofday(&currentTime, NULL);
	return currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;
}

int num_ok(int a, int x, int y){
    if(a>y || a<x){
        return 0;
    }
    return 1;
}

int find_div(int n, int k){
    int d_cnt = 0;
    int loop_cnt = 0;
    while(d_cnt != k){
        if(loop_cnt>n){
            return 0;
        }
        loop_cnt++;
        if(n%loop_cnt == 0){
            //printf("%d %d \n",n, loop_cnt);
            d_cnt++;
        }
        //printf(".");
    }
    return loop_cnt;
}

int main(void){
    long start = 0, end = 0;
    double e_time = 0;
    float test_t = 0;

    int n,k;
    scanf("%d %d",&n,&k);
    start = getMicrotime(); // 수행 시간 측정 시작
    

    if(!(num_ok(n,1,10000)||num_ok(k,1,n))){
        printf("INPUT ERROR");
    }
    printf("%d\n",find_div(n,k));
    
    end = getMicrotime(); //시간 측정 끝
    e_time = (double)(end - start)/1000;
    
    printf("%lf ms\n",e_time);
    return 0;
}