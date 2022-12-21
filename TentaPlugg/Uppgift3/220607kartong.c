#include <stdio.h>
#include <string.h>
#define charMax 10

struct carton{
    float length, height, width;
    char type[charMax];
}; typedef struct carton Box;

void printBox(Box b);
Box changeCharacter(Box b);

int main(void)
{
    Box box1 = {3.20, 4, 5, "fragile"};
    printBox(box1);
    box1 = changeCharacter(box1);
    printBox(box1);
}

void printBox(Box b)
{
    printf("(%.2f, %.2f, %.2f) - %s\n", b.length, b.height, b.width, b.type);
}

Box changeCharacter(Box b)
{
    if(strcmp(b.type,"fragile")== 0)
    {
        strcpy(b.type, "sturdy");
    } 
    else
    {
        strcpy(b.type, "fragile");
    }
    return b;
}