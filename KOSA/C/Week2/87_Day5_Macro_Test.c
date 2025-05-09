#include <stdio.h>


// #연산자를 통해 입력 된 인자를 문자열로 변환한다.(문자열은 "로 구분되어 나열될 수 있다.)
#define STR(NAME, ADDR, YEAR) #ADDR "에 사시는 " #YEAR "년생 " #NAME

// 숫자를 단순히 합치려면 아래 두가지 방법이 있다.
#define STNUM(Y,S,P) ((Y)*1000*1000 + (S)*1000 + (P))
// 아래 방법은 입력인자를 단순하게 합친다.
#define CONCAT(UPP,LOW) UPP ## 17 ## LOW

int main(void){
    printf(STR(홍길동,서울,00)"\n");
    printf("학번: %d"  "\n", STNUM(20,111,173));
    printf("string: %d",CONCAT(18,19));
    return 0;
}