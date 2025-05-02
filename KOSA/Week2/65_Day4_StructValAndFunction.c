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

Point getCurrentPosition(void){
    Point cen;
    printf("Input current pos: ");
    scanf("%d %d", &cen.xpos, &cen.ypos);
    return cen;
}

int main(void){
    Point pos = getCurrentPosition();
    ShowPosition(pos);
    return 0;
}