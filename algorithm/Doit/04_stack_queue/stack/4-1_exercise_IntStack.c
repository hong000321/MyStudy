#include <stdio.h>
#include <stdlib.h>
#include "4-1_exercise_IntStack.h"


int Initialize(IntStack *s, int max){
    if((s->stk = calloc(max, sizeof(int))) == NULL){
        s->max = 0;
        return -1;
    }
    s->num[0] = 0;
    s->num[1] = 0;
    s->max = max;
    return 0;
}

// 두 스택 탑의 포인터 위치를 반환
int TopPtr(IntStack *s, int is_b){
    return s->num[is_b] - 2*is_b*s->num[is_b] + is_b*(s->max-1);
}

// 두 스택 중 한 곳에 x를 삽입
int Push(IntStack *s, int is_b, int x){
    // 두 스택의 수가 max를 넘는지 확인
    if((s->num[1] + s->num[0])>=s->max){
        return -1;
    }
    // 스택의 현재 top위치에 x 대입 후 사이즈 1증가
    s->stk[TopPtr(s,is_b)] = x;
    s->num[is_b]++;
    return 0;
}

// 두 스택 중 한 곳의 값 제거 후 해당 값을 x에 반환
int Pop(IntStack *s, int is_b, int *x){
    // 스택 크기가 0이라면 안되니 체크
    if(s->num[is_b] <= 0){
        return -1;
    }
    s->num[is_b]--; // 위치를 -1하여 제거
    *x = s->stk[TopPtr(s,is_b)];
    return 0;
}

int Peek(const IntStack *s,int is_b, int *x){
    if(s->num<=0){
        return -1;
    }
    *x = s->stk[TopPtr(s,is_b) + 2*is_b - 1];
    return 0;
}

void Clear(IntStack *s, int is_b){
    s->num[is_b] = 0;
}

int Capacity(const IntStack *s){
    return s->max;
}

int Size(const IntStack *s, int is_b){
    return s->num[is_b];
}

int IsEmpty(const IntStack *s, int is_b){
    return (s->num[is_b] <= 0);
}

int IsFull(const IntStack *s){
    return ((s->num[0] + s->num[1]) >= s->max);
}

int Search(const IntStack *s, int is_b, int x){  //탐색은 top->bottom 으로 
    for(int i=s->num[is_b]-1; i>=0 ; i--){
        if(s->stk[i-is_b*2*i+is_b*(s->max-1)] == x){
            return i;
        }
    }
    return -1;
}

void Print(const IntStack *s, int is_b){
    for(int i=0; i<s->num[is_b] ; i++){
        printf("%d ",s->stk[i-is_b*2*i+is_b*(s->max-1)]);
    }
    putchar('\n');
}

void Terminate(IntStack *s){
    if(s->stk != NULL){
        free(s->stk);
    }
    s->max = 0;
    s->num[0] = 0;
    s->num[1] = 0;
}

int main(void){
    IntStack s;
    if(Initialize(&s,6) == -1){
        puts("스택 생성에 실패하였습니다.");
        return -1;
    }

    while(1){
        int menu, is_b, x;
        printf("현재 데이터 수: %d, %d / %d\n", Size(&s,0), Size(&s,1), Capacity(&s));
        printf("(1)푸시 (2)팝 (3)피크 (4)탐색 (5)출력 (0)종료: ");
        scanf("%d", &menu);

        if(menu == 0) break;
        switch (menu)
        {
        case 1:
            printf("index: ");
            scanf("%d", &is_b);
            printf("데이터: ");
            scanf("%d", &x);
            if(Push(&s, is_b, x) == -1)
                puts("\a오류: 푸싱 실패했습니다.");
            break;
        case 2:
            printf("index: ");
            scanf("%d", &is_b);
            if(Pop(&s, is_b, &x) == -1)
                puts("\a오류: 팝에 실패했습니다.");
            else
                printf("팝 데이터는 %d 입니다.\n",x);
            break;

        case 3:
            printf("index: ");
            scanf("%d", &is_b);
            if(Peek(&s,is_b,&x) == -1)
                puts("\a오류: 피크에 실패했습니다.");
            else
                printf("피크 데이터는 %d입니다.\n",x);
            break;

        case 4:
            printf("index: ");
            scanf("%d", &is_b);
            printf("탐색 값: ");
            scanf("%d", &x);
            if((x=Search(&s, is_b, x)) == -1)
                puts("\a오류: 탐색에 실패했습니다.");
            else
                printf("탐색 데이터는 %d입니다.\n",x);
            break;
                
        case 5:
            printf("index: ");
            scanf("%d", &is_b);
            Print(&s,is_b);
            break;
        }
    }
    Terminate(&s);
    return 0;
}