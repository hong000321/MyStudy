#include <iostream>
#include <mem.h>
using namespace std;

class Stack{
protected:
    int m_size;
    int m_top;
    int *m_buf;
public:
    void Initialize(int size = 10);
    void RemoveAll();
    bool Push(int value);
    bool Pop(int& value);
    void Print();
    bool SetSize(int size);
    bool GetData(int index, int& data);
};


int main(void){
    int val[5] = {1,3,2,4,5};
    int oval;
    Stack stack;
    stack.Initialize(5);
    // stack.m_top = 1; //컴파일 에러
    for(int i=0; i<5; i++){
        stack.Push(val[i]);
    }
    // delete stack.m_buf //컴파일 에러

    stack.Print();
    stack.Pop(oval);
    stack.Print();
    stack.SetSize(4);
    stack.Push(11);
    stack.Print();
    

    return 0;
}


void Stack::Initialize(int size){
    m_size = size;
    m_top = -1;
    m_buf = new int[m_size];
    //memset(m_buf, 0 , sizeof(int) * m_size);
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


bool Stack::SetSize(int size){
    if(size<m_top+1) return false;
    int* tmp = m_buf;
    m_size = size;
    m_buf = new int[m_size];
    memcpy(m_buf, tmp, sizeof(int)*(m_top+1));
    delete [] tmp;
    return true;
}

bool Stack::GetData(int index, int& data){
    if(index<0 || index>m_top) return false;
    data = m_buf[index];
    return true;
}