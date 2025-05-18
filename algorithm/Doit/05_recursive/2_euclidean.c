#include <stdio.h>
#include "../tip/mytime.h"

#define lld unsigned long long int
int recurs_time = 0;

lld func(lld a, lld b){
	recurs_time++;
	lld r;      // q의 값은 gcd를 구함에 있어 사실상 쓸모없음, 
				// 실제로 다음 회귀에 넘어가는 a%b의 나머지를 r로 저장
	lld ret;    // gcd를 반환 할 변수;
	r=a%b;      // r(나머지)를 저장
	if(r<=0)    // r(나머지)가 0일때의 b가 gcd임으로 b를 반환
		return b;
	ret = func(b,r);  // 마지막 재귀에서 반환된 값을 ret에 저장하여 다시 반환
	return ret;
}

lld func2(lld a, lld b){
	recurs_time++;
	if(b == 0)		// b 는 이전 재귀함수의 r값
		return a;	// a 는 이전 재귀함수의 b값
	else
		return func2(b,a%b); // b=0일때의 값을 최종적으로 반환 받음
}


int main(void){
	tic(0);
	// ======================================================
    lld a = 12200160415121876738LLU;
    lld b = 7540113804746346429LLU;
    lld ret = func(a,b);

	for(int i=1; i < 1000; i++){
		for(int j=1; j < 1000; j++){
			ret = func(i,j);
		}
	}
	// ======================================================
	toc(0);

    printf("%llu,%llu의 최소공배수는 %llu입니다.%d\n",a,b,ret,recurs_time);
    return 0;
}