#include <stdio.h>

int num_ok(int a){
    if(a>1000 || a<100){
        return 0;
    }
    return 1;
}

int main(void){
    int x1, x2, x3;
    int result = 0;
    int list[10] = {0};
    int tmp_num = 0;
    scanf("%d %d %d",&x1, &x2, &x3);
    
    if((num_ok(x1) && num_ok(x2) && num_ok(x3)) == 0){
        printf("INPUT ERROR");
        return 0;
    }

    result = x1*x2*x3;

    while(result!=0){
        list[result%10] += 1;
        result /= 10;
    }
    for(int i = 0; i<10 ; i++){
        printf("%d\n", list[i]);
    }
        
    return 0;
}