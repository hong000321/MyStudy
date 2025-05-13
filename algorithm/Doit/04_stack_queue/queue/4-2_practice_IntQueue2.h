#ifndef ___IntQueue
#define ___IntQueue

typedef struct {
    int max;
    int num;
    int front;
    int rear;
    int *que;
}IntQueue;

int Initialize(IntQueue *q,int max);
int EnQueue(IntQueue *q, int x);
int DeQueue(IntQueue *q, int *x);
int Peak(IntQueue *q, int *x);
void Clear(IntQueue *q);
int Capacity(IntQueue *q);
int Size(IntQueue *q);
int IsEmpty(const IntQueue *q);
int IsFull(const IntQueue *q);
int Search(const IntQueue *q, int x);
void Print(IntQueue *q);
void Terminate(IntQueue *q);

#endif