/**
 * 문제
 * M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.
 * 
 * 입력
 * 첫째 줄에 자연수 M과 N이 빈 칸을 사이에 두고 주어진다. (1 ≤ M ≤ N ≤ 1,000,000) M이상 N이하의 소수가 하나 이상 있는 입력만 주어진다.
 * 
 * 출력
 * 한 줄에 하나씩, 증가하는 순서대로 소수를 출력한다.
 */


#include <stdio.h>
#include <stdbool.h>


#define MIN_N 1
#define MAX_N 123456

int main(void){
    
    bool flag[MAX_N*2+1] = {false,};
    flag[0]=flag[1]=true;
    
    for(int i=2; i*i<=2*MAX_N ; i++){
        if (!flag[i]) {
            for(int j=i*i; j<=2*MAX_N; j+=i){
                flag[j]=true;
            }
        }
    }
    while(1){
        int n,cnt=0;
        scanf("%d",&n);
        if(n==0){
            break;
        }
        
        for(int i=n+1; i<=2*n; i++){
            if(!flag[i]){
                cnt++;
            }
        }
        printf("%d\n",cnt);
    }
    scanf("%d");

    return 0;
}