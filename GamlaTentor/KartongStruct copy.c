#include <stdio.h>

struct box
{
    float length, width, height;
    int fragile;
};

void printBox(struct box b);
struct box changeCharacter(struct box b);

int main()
{
    struct box box1 = {3.2,4,5,1};
    printBox(box1);
    struct box box12 = changeCharacter(box1);
    printBox(box12);

    return 0;
}

struct box changeCharacter(struct box box1)
{
    box1.fragile = 0;
    return box1;
} 

void printBox(struct box b)
{
    printf("(%.2f, %.2f, %.2f, %d) - ", b.length, b.width, b.height, b.fragile);
    
    if(b.fragile == 1)
    {
        printf("fragile\n");
    }
    else
    {
        printf("sturdy\n");
    }
   
}
