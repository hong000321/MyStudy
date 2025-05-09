#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct point
{
    int xpos;
    int ypos;
}Point;

typedef struct rectangle
{
    Point p1; //좌 상단
    Point p2; //우 하단
} Rectangle;

void ShowRectSize(Rectangle rect){
    int w = rect.p2.xpos - rect.p1.xpos;
    int h = rect.p1.ypos - rect.p2.ypos;
    printf("size = %d\n", w*h);
}

void ShowRectInfo(Rectangle rect){
    printf("1. [%d, %d] \n",rect.p1.xpos,rect.p1.ypos);
    printf("2. [%d, %d] \n",rect.p2.xpos,rect.p1.ypos);
    printf("3. [%d, %d] \n",rect.p1.xpos,rect.p2.ypos);
    printf("4. [%d, %d] \n",rect.p2.xpos,rect.p2.ypos);
}

int main(void){
    Rectangle r1 = {1,7,4,3};
    Rectangle r2 = {3,4,7,2};
    ShowRectSize(r1);
    ShowRectInfo(r1);
    return 0;
}