#include <stdio.h>
#include <string.h>

struct boxes
{
    char color[30];
    int width, depth, height; 
}; typedef struct boxes Box; 

void printBox(Box b);
void doubleHeight(Box *box1);
Box createBoxforBoxes(Box b1, Box b2);
int checkMax(int box1, int box2);
int total(int a, int b);
int fitBox(Box b1, Box b2);



int main(void){

    Box myBox1 = {"Gul", 7, 10, 12};
    Box myBox2 = {"Svart", 8,11,3};

    printBox(myBox1);
    printBox(myBox2);

    doubleHeight(&myBox2);
    printBox(myBox2);
    createBoxforBoxes(myBox1, myBox2);
    printBox(createBoxforBoxes(myBox1,myBox2));
    fitBox(myBox1,myBox2);
    printf("%d", fitBox(myBox1,myBox2));

}

void printBox(Box b)
{
    printf("%s %d*%d*%d\n", b.color, b.width, b.depth, b.height);
}

void doubleHeight(Box *box1)
{
    box1 -> height *= 2;
}

Box createBoxforBoxes(Box b1, Box b2)
{
    Box b;
    strcpy(b.color, "Vit");
    b.width = checkMax(b1.width, b2.width);
    b.depth = checkMax(b1.depth, b2.depth);
    b.height = total(b1.height, b2.height);
    return b;   
}

int checkMax(int a, int b)
{
    if (a > b)
    {
        return a;
    } else 
    {
        return b;
    }
}

int total(int a, int b)
{
    int total;
    total = a+b;

    return total;
}



int fitBox(Box b1, Box b2)
{
    if ((b1.width > b2.width && b1.depth > b2.depth && b1.height > b2.height) || 
        (b1.width > b2.height && b1.depth > b2.width && b1.height > b2.depth) ||
        (b1.width > b2.depth && b1.depth > b2.height && b1.height > b2.width)) {
        return 1;
    }
    else if ((b1.depth > b2.width && b1.width > b2.depth && b1.height > b2.height) ||
             (b1.depth > b2.height && b1.width > b2.width && b1.height > b2.depth) ||
             (b1.depth > b2.depth && b1.width > b2.height && b1.height > b2.width)) {
        return 1;
    }
    else if ((b1.height > b2.width && b1.depth > b2.depth && b1.width > b2.height) ||
             (b1.height > b2.height && b1.depth > b2.width && b1.width > b2.depth) ||
             (b1.height > b2.depth && b1.depth > b2.height && b1.width > b2.width)) {
        return 1;
    } 
    else
    return 0;
}