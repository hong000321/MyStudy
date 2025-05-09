#include <stdio.h>

void solver(int *a, int *b, int *c){
    int i,j,k;   // 반복문에 사용 할 변수 미리 선언
    int cola = 400;   // 각 제품 가격
    int shrimp = 700;
    int cream = 500;
    int remain = 3500; // dvd사고 남은 돈
    
    for(i=1; i<=(remain/cola); i++){ // 살 수 있는 갯수를 한정하기 위해 남은 돈에서 가격을 나눔/ 또한 하나 이상씩은 사야하기 때문에 1부터 시작
        for(j=1; j<=(remain/shrimp); j++){
            for(k=1; k<=(remain/cream); k++){
                if((i*cola+j*shrimp+k*cream) == remain){ // 가격과 갯수들의 합이 남은 돈과 같으면 변수들에 값을 저장하고 함수 종료
                    *a=k;
                    *b=j;
                    *c=i;
                    return;
                }
            }
        }
    }
}

int main(void){
    int cola_n,shrimp_n,cream_n;  // 정답인 수들을 정의
    
    solver(&cream_n,&shrimp_n,&cola_n); //각 변수들에 정답 가져오기

    printf("크림빵 %d개, 새우깡 %d개, 콜라 %d개",cream_n,shrimp_n,cola_n); // 정답 출력

    return 0;
}