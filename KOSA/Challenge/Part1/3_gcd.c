#include <stdio.h>  // scanf, printf를 위한 헤더파일 추가

/**
 * 두 수중 작은 수를 골라 해당 값부터 0까지 두 수 모두 나눠 떨어지는 값을 찾는 방식
 */
int gcd_solver1(int a, int b){
    int i;
    int i_max = (a>b)?b:a;
    for(i=i_max; i>=1; i--){
        if((a%i)==0 && (b%i)==0){
            return i;
        }
    }
    return -1;
}

/**
 * 유클리드 호제법을 사용한 방식
 * a = b*q + r 일때 a,b의 최대공약수는 b,r의 최대공약수와 같다는 알고리즘 방식
 * 따라서 r(a,b에 대한 나머지)를 구할 수 있으므로  재귀함수를 사용하여 최종적으로 r이 0이 되는 지점을 찾으면 이때의 입력 b가 최대공약수가 된다.
 * 
 * 참조 : https://namu.wiki/w/%EC%9C%A0%ED%81%B4%EB%A6%AC%EB%93%9C%20%ED%98%B8%EC%A0%9C%EB%B2%95
 * ex)
 *  4212=2484×1+1728
    2484=1728×1+756
    1728=756×2+216
    756=216×3+108
    216=108×2
 */
int gcd_solver2(int a, int b){
    int r;
    r = a%b;
    if(r==0){
        return b;
    }
    return gcd_solver2(b,r);
}

// main
int main(void){
    int a, b, gcd;
    printf("두 개의 정수 입력: ");
    scanf("%d %d",&a, &b);  // a와 b에 두 정수 입력

    gcd = gcd_solver2(a,b); // a와 b를 함수에 입력
    printf("두 수의 최대공약수: %d",gcd);

    return 0;
}