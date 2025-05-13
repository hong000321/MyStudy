#ifndef ___IntQueue
#define ___IntQueue

typedef struct {
    int max;
    int num;
    int *que;
}IntQueue;

int Initialize(IntQueue *q,int max);
int Size(IntQueue *q);
int Capacity(IntQueue *q);
int EnQueue(IntQueue *q, int x);
int DeQueue(IntQueue *q, int *x);
int Front(IntQueue *q, int *x);
void Print(IntQueue *q);
void Terminate(IntQueue *q);

#endif