#include <stdio.h>
#include <stdlib.h>
#include "4-1_practice_IntStack.h"

int Initialize(IntStack *s, int max){
    s->ptr = 0;
    if((s->stk = calloc(max, sizeof(int))) == NULL){
        s->max = 0;
        return -1;
    }
    s->max = max;
    return 0;
}

int Push(IntStack *s, int x){
    if(s->max <= s->ptr){
        return -1;
    }
    s->stk[s->ptr++] = x;
    return 0;
}

int Pop(IntStack *s, int *x){
    if(s->ptr <= 0){
        return -1;
    }
    *x = s->stk[--s->ptr];
    return 0;
}

int Peek(const IntStack *s, int *x){
    if(s->ptr <= 0){
        return -1;
    }
    *x = s->stk[s->ptr - 1];
    return 0;
}

void Clear(IntStack *s){
    s->ptr = 0;
}

int Capacity(const IntStack *s){
    return s->max;
}

int Size(const IntStack *s){
    return s->ptr;
}

int IsEmpty(const IntStack *s){
    return (s->ptr <= 0);
}

int IsFull(const IntStack *s){
    return (s->max <= s->ptr);
}

int Search(const IntStack *s, int x){  //탐색은 top->bottom 으로 
    for(int i=s->ptr-1; i>=0 ; i--){
        if(s->stk[i] == x){
            return i;
        }
    }
    return -1;
}

void Print(const IntStack *s){
    for(int i=0; i<s->ptr ; i++){
        printf("%d ",s->stk[i]);
    }
    putchar('\n');
}

void Terminate(IntStack *s){
    if(s->stk != NULL){
        free(s->stk);
    }
    s->max = 0;
    s->ptr = 0;
}



int main(void){
    IntStack s;
    if(Initialize(&s,64) == -1){
        puts("스택 생성에 실패하였습니다.");
        return -1;
    }

    while(1){
        int menu, x;
        printf("현재 데이터 수: %d / %d\n", Size(&s), Capacity(&s));
        printf("(1)푸시 (2)팝 (3)피크 (4)출력 (0)종료: ");
        scanf("%d", &menu);

        if(menu == 0) break;
        switch (menu)
        {
        case 1:
            printf("데이터: ");
            scanf("%d", &x);
            if(Push(&s,x) == -1)
                puts("\a오류: 푸싱 실패했습니다.");
            break;
        case 2:
            if(Pop(&s, &x) == -1)
                puts("\a오류: 팝에 실패했습니다.");
            else
                printf("팝 데이터는 %d 입니다.\n",x);
            break;

        case 3:
            if(Peek(&s,&x) == -1)
                puts("\a오류: 피크에 실패했습니다.");
            else
                printf("피크 데이터는 %d입니다.\n",x);
            break;
        
        case 4:
            Print(&s);
            break;
        }
    }
    Terminate(&s);
    return 0;
}