#include <stdio.h>
#include <string.h>

typedef struct point
{
    int xpos;
    int ypos;
} Point;

void ShowPosition(Point pos){
    printf("[%d, %d] \n", pos.xpos, pos.ypos);
}

Point SwapPosition(Point *pos1, Point *pos2){
    Point tmpPos = *pos1;
    *pos1 = *pos2;
    *pos2 = tmpPos;
}

int main(void){
    Point pos1 = {5, 6};
    Point pos2 = {2, 9};
    
    ShowPosition(pos1);
    ShowPosition(pos2);

    SwapPosition(&pos1, &pos2);
    ShowPosition(pos1);
    ShowPosition(pos2);

    return 0;
}