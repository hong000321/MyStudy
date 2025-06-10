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

void findLCM(int a, int b){
    int mul_max_num = a*b;
    for(int i = 0; i<mul_max_num ; i++){
        
    }

}


void findDiv(int a, int arr_a[]){
    int div_cnt = 0;
    int div_cnt_odd = 0;
    int tmp_arr[1000] = {0};
    for(int i = 1; i<=(int)sqrt(a) && div_cnt<1000 ; i++){
        if(a%i == 0){
            arr_a[div_cnt] = i;
            if(i == a/i){
                div_cnt_odd++;
                break;
            }
            tmp_arr[div_cnt] = a/i;
            div_cnt++;
        }
    }

    for(int i = 0; i<=div_cnt-div_cnt_odd ; i++){
        arr_a[div_cnt + i - 1] = tmp_arr[div_cnt - div_cnt_odd - i]; // tmp_arr는 큰수부터 작은 수 순서로 나열되어있음
    }
}

int findGCD(int a, int b){
    int arr_a[1000] = {0};
    int arr_b[1000] = {0};
    int max = 0;
    findDiv(a, &arr_a[0]);
    findDiv(b, &arr_b[0]);

    for(int i = 0; i<1000 ; i++){
        for(int j = 0; j<1000 ; j++){
            if(arr_a[i] != 0 && arr_b[j] != 0){    
                if(arr_a[i] == arr_b[j] && arr_a[i]>max){
                    max = arr_a[i];
                }
            }
        }
    }
    return max;
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
    printf("gcd = %d\n",gcd);
    end = getMicrotime(); //시간 측정 끝
    time = (double)(end - start);
    printf("%lf ms\n",time/1000);
    return 0;
}