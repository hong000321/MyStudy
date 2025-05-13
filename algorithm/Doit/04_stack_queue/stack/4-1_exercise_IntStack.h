#ifndef ___IntStack
#define ___IntStack

typedef struct {
    int max;
    int num[2]; // 2개의 스택을 관리 하기 위한 크기 2의 배열
    int *stk;
} IntStack;

int Initialize(IntStack *s, int max);

// 스택 A ,B 선택을 위한 ptr_n 추가
int Push(IntStack *s, int ptr_n, int x);

// 스택 A ,B 선택을 위한 ptr_n 추가
int Pop(IntStack *s, int ptr_n, int *x);

// 스택 A ,B 선택을 위한 ptr_n 추가
int Peek(const IntStack *s, int ptr_n, int *x);

void Clear(IntStack *s, int ptr_n);

int Capacity(const IntStack *s);

// 스택 A ,B 선택을 위한 ptr_n 추가
int Size(const IntStack *s, int ptr_n);

// 스택 A ,B 선택을 위한 ptr_n 추가
int IsEmpty(const IntStack *s, int ptr_n);

int IsFull(const IntStack *s);

// 스택 A ,B 선택을 위한 ptr_n 추가
int Search(const IntStack *s, int ptr_n, int x);

// 스택 A ,B 선택을 위한 ptr_n 추가
void Print(const IntStack *s, int ptr_n);

void Terminate(IntStack *s);




#endif