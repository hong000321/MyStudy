#include <stdio.h>
#include <string.h>

typedef struct point
{
    int xpos;
    int ypos;
} Point;

Point AddPoint(Point pos1, Point pos2){
    Point pos={pos1.xpos+pos2.xpos, pos1.ypos+pos2.ypos};
    return pos;
}

Point MinPoint(Point pos1, Point pos2){
    Point pos={pos1.xpos-pos2.xpos, pos1.ypos-pos2.ypos};
    return pos;
}

void ShowPosition(Point pos){
    printf("[%d, %d] \n", pos.xpos, pos.ypos);
}

int main(void){
    Point pos1 = {5, 6};
    Point pos2 = {2, 9};
    
    Point result = AddPoint(pos1,pos2);
    ShowPosition(result);

    result=MinPoint(pos1,pos2);
    ShowPosition(result);
    return 0;
}