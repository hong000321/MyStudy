#include <stdio.h>

int num_ok(int a, int x, int y){
    if(a>y || a<x){
        return 0;
    }
    return 1;
}

int divmulti(int base, int target){
    int tmp = 0;
    
    tmp = (base>target)?(base%target):(target%base);
    if(tmp==0){
        return 1;
    }
    return 0;
}


int main(void){
    int input_num = 0;
    int int_list[40] = {0};
    int dm_num = 0;
    int d_sum = 0;
    int m_sum = 0;
    scanf("%d",&input_num);

    if(num_ok(input_num,1,40) == 0){
        printf("INPUT ERROR");
        return 0;
    }
    for(int i = 0 ; i<input_num ; i++){
        scanf("%d",&int_list[i]);
    }
    
    scanf("%d",&dm_num);

    if(num_ok(dm_num,1,100) == 0){
        printf("INPUT ERROR");
        return 0;
    }
    for(int i = 0 ; i<input_num ; i++){
        int ok = 0;
        ok = divmulti(dm_num,int_list[i]);
        if(ok && (int_list[i]>=dm_num)){
            m_sum += int_list[i];
        }
        if(ok && (int_list[i]<=dm_num)){
            d_sum += int_list[i];
        }
    }
    printf("%d \n%d", d_sum, m_sum);
    
    
    return 0;
}