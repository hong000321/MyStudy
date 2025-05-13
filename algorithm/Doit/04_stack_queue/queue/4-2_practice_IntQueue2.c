#include <stdio.h>
#include <stdlib.h>
#include "4-2_practice_IntQueue2.h"


int Initialize(IntQueue *q, int max){
    q->que = calloc(max,sizeof(int)); // max만큼 초기화
    if(q == NULL){
        q->max = 0;
        return -1;
    }
    q->max = max; // 성공 시 max값 적용 및 기타 값 초기화
    q->num = 0;
    q->front = 0;
    q->rear = 0;
    return 0;
}

int EnQueue(IntQueue *q, int x){
    // 요소 수가 최대값을 넘는지 확인
    if(q->max <= q->num){
        return -1;
    }
    q->num++;  // 요소 개수 +1
    q->que[q->rear++] = x; // 요소들의 뒷쪽에 데이터 삽입

    // 링 버퍼 구조를 위해 rear가 max이면 0으로 순환구조 만듦
    if(q->rear >= q->max){
        q->rear = 0;
    }
    return 0;
}

int DeQueue(IntQueue *q, int *x){
    // 요소가 없으면 -1 반환
    if(q->num <= 0){
        return -1;
    }
    q->num--; // 요소 개수 -1

    // 현재 값을 x에 대입 후 front++로 앞쪽 데이터를 지움
    *x = q->que[q->front++];

    // 링 버퍼를 구조를 위해 front가 max보다 크면 0으로 변경
    if(q->front>=q->max){
        q->front = 0;
    }
    return 0;
}

int Peak(IntQueue *q, int *x){
    if(q->num <= 0){
        return -1;
    }
    *x = q->que[q->front];
    return 0;
}

void Clear(IntQueue *q){
    q->num = 0;
    q->front = 0;
    q->rear = 0;
}

int Capacity(IntQueue *q){
    return q->max;
}

int Size(IntQueue *q){
    return q->num;
}

int IsFull(const IntQueue *q){
    return (q->max <= q->num);
}

int IsEmpty(const IntQueue *q){
    return (q->num<=0);
}

int Searchi_my(const IntQueue *q, int x){
    int index=q->rear;
    int count=q->num;
    if(q->num<=0){
        return -1;
    }

    while(1){
        if(count <= 0){
            return -1;
        }
        if(x == q->que[index]){
            break;
        }
        index--;
        if(index < 0){
            index = q->max;
        }
        count--;
    }
    return index;
}

int Search(const IntQueue *q, int x){
    for(int i=0; i<q->num; i++){
        int index;
        if(q->que[index = (i+q->front)%q->max] == x){
            return index;
        }
    }
    return -1;
}

void Print(IntQueue *q){
    for(int i=0; i<q->num ; i++){
        printf("%d ",q->que[(i+q->front)%q->max]);
    }
    putchar('\n');
}
void Terminate(IntQueue *q){
    if(q->que != NULL){
        free(q->que);
    }
    q->max = 0;
    q->num = 0;
    q->rear = 0;
    q->front = 0;
}

int main(void){
    IntQueue q;
    if(Initialize(&q,4) == -1){
        puts("큐 생성에 실패하였습니다.");
        return -1;
    }

    while(1){
        int menu, x;
        printf("현재 데이터 수: %d / %d\n", Size(&q), Capacity(&q));
        printf("(1)인큐 (2)디큐 (3)프론트 (4)서치 (5)출력 (0)종료: ");
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
            scanf("%d",&x);
            if((x = Search(&q,x)) == -1)
                puts("\a오류: 서치에 실패했습니다.");
            else
                printf("서치 데이터는 %d입니다.\n",x);
            break;
        
        case 5:
            Print(&q);
            break;
        }
    }
    Terminate(&q);
    return 0;
}