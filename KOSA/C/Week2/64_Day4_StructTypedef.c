#include <stdio.h>
#include <string.h>

struct point
{
    int xpos;
    int ypos;
    struct point *ptr;
};

typedef struct point Point; 

typedef struct person
{
    char name[20];
    char phoneNum[20];
    int age;
}Person;


int main(void){
    Point pos={10, 20};
    Person man={"이승기", "010-1212-0001", 21};

    printf("%p %p %p\n"  , &pos, &pos.xpos, &pos.ypos);
    printf("%p %p %p\n\n", &pos, &pos.xpos+1, &pos.ypos);
    printf("%p %p %p\n", &man, &man.name, &man.age);
    return 0;
}