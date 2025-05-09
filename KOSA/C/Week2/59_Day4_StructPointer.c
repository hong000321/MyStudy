#include <stdio.h>
#include <string.h>

struct point
{
    int xpos;
    int ypos;
};

int main(void){
    struct point pos1={1,2};
    struct point pos2={100,200};
    struct point * pptr = &pos1;

    (*pptr).xpos += 4;
    (*pptr).ypos += 5;
    printf("[%d, %d] \n", pptr->xpos, pptr->ypos);

    pptr=&pos2;
    pptr->xpos += 1;  // 구조체가 포인터 형태라면 포인터의 값을 가져온 후 "."을 통해 값에 접근이 가능하다.(포인터 접근* + 멤버 접근.)
    pptr->ypos += 2;  // "->" 연산자는 포인터의 주소값에서 바로 멤버 접근이 가능하다. (포인터 주소의 멤버 접근->)
    printf("[%d, %d] \n", (*pptr).xpos, (*pptr).ypos);

    return 0;
}