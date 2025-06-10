#include <stdio.h>
#include <sys/time.h>

long getMicrotime(){
	struct timeval currentTime;
	gettimeofday(&currentTime, NULL);
	return currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;
}

int main(void){
    long start, end; 
    double time;

    int n,k;
    int d_cnt = 0;
    int loop_cnt = 0;
    
    scanf("%d %d",&n,&k);
    start = getMicrotime(); // 수행 시간 측정 시작
    while(d_cnt != k){
        if(loop_cnt>n){
            loop_cnt = 0;
            break;
        }
        loop_cnt++;
        if(n%loop_cnt == 0){
            d_cnt++;
        }
    }
    

    printf("%d\n",loop_cnt);
    end = getMicrotime(); //시간 측정 끝
    time = (double)(end - start);
    printf("%lf ms\n",time/1000);
    return 0;
}