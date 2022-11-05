#include <stdio.h>

struct box{
    float length, width, height;
    int fragile;
};
typedef struct box Box;

void printBox(Box b);
Box changeCharacter(Box b);

int main(){
    Box box1 = {3.2,4,5,1};
    printBox(box1);
    Box box2 = changeCharacter(box1);
    printBox(box2); 
    return 0;
}

Box changeCharacter(Box b){
    Box box = b;
    box.fragile = !box.fragile;
    return box;
}

void printBox(Box b){
    printf("(%.2f,%.2f,%.2f) - ",b.length,b.width,b.height);
    if(b.fragile == 1)
        printf("fragile\n");
    else
        printf("sturdy\n");
}