#include <stdio.h>
#include <stdlib.h>
#include "4-2_practice_IntQueue.h"


int Initialize(IntQueue *q, int max){
    q->que = calloc(max,sizeof(int));
    if(q == NULL){
        q->max = 0;
        return -1;
    }
    q->max = max;
    q->num = 0;
    return 0;
}

int Size(IntQueue *q){
    return q->num;
}

int Capacity(IntQueue *q){
    return q->max;
}
int EnQueue(IntQueue *q, int x){
    if(q->max <= q->num){
        return -1;
    }
    q->que[q->num++] = x;
    return 0;
}
int DeQueue(IntQueue *q, int *x){
    if(q->num <= 0){
        return -1;
    }
    *x = q->que[0];
    q->num--;
    for(int i = 0; i<q->num ; i++){
        q->que[i] = q->que[i+1];
    }
    return 0;
}
int Front(IntQueue *q, int *x){
    if(q->num <= 0){
        return -1;
    }
    *x = q->que[0];
    return 0;
}
void Print(IntQueue *q){
    for(int i=0; i<q->num ; i++){
        printf("%d ",q->que[i]);
    }
    putchar('\n');
}
void Terminate(IntQueue *q){
    if(q->que != NULL){
        free(q->que);
    }
    q->max = 0;
    q->num = 0;
}

int main(void){
    IntQueue q;
    if(Initialize(&q,64) == -1){
        puts("큐 생성에 실패하였습니다.");
        return -1;
    }

    while(1){
        int menu, x;
        printf("현재 데이터 수: %d / %d\n", Size(&q), Capacity(&q));
        printf("(1)인큐 (2)디큐 (3)프론트 (4)출력 (0)종료: ");
        scanf("%d", &menu);

        if(menu == 0) break;
        switch (menu)
        {
        case 1:
            printf("데이터: ");
            scanf("%d", &x);
            if(EnQueue(&q,x) == -1)
                puts("\a오류: 인큐 실패했습니다.");
            break;
        case 2:
            if(DeQueue(&q, &x) == -1)
                puts("\a오류: 디큐에 실패했습니다.");
            else
                printf("디큐 데이터는 %d 입니다.\n",x);
            break;

        case 3:
            if(Peak(&q,&x) == -1)
                puts("\a오류: 피크에 실패했습니다.");
            else
                printf("피크 데이터는 %d입니다.\n",x);
            break;
        
        case 4:
            Print(&q);
            break;
        }
    }
    Terminate(&q);
    return 0;
}