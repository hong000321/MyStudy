#include <iostream>
#include <mem.h>
using namespace std;

class Stack{
public:
    int m_size;
    int m_top;
    int *m_buf;

    void Initialize(int size = 10);
    void RemoveAll();
    bool Push(int value);
    bool Pop(int& value);
    void Print();
};


int main(void){
    int val[5] = {1,3,2,4,5};
    int oval;
    Stack stack;
    stack.Initialize(5);
    for(int i=0; i<5; i++){
        stack.Push(val[i]);
    }

    stack.Print();
    stack.Pop(oval);
    stack.Print();

    return 0;
}


void Stack::Initialize(int size){
    m_size = size;
    m_top = -1;
    m_buf = new int[m_size];
    memset(m_buf, 0 , sizeof(int) * m_size);
}

void Stack::RemoveAll(){
    m_size = 0;
    m_top = -1;
    delete[] m_buf;
    m_buf = nullptr;
}

bool Stack::Push(int value){
    if(m_top >=m_size-1 ) return false;
    m_buf[++m_top] = value;
    return true;
}

bool Stack::Pop(int& value){
    if(m_top <0 ) return false;
    value = m_buf[m_top--];
    return true;
}

void Stack::Print(){
    if(m_top<0){
        cout << "stack is null" << endl;
    }
    for(int i = 0; i<=m_top; i++){
        cout << m_buf[i] << " ";
    }
    cout << endl;
}
