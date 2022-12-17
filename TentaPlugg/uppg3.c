#include <stdio.h>
#include <string.h>
#define COLOURSIZE 31

struct box{
    char colour[COLOURSIZE];
    int width, depth, height;
};
typedef struct box Box;

void printBox(Box b);
void doubleHeight(Box *pBox);
Box createBoxForBoxes(Box b1, Box b2);
int max(int a, int b);
int fit(Box bOut, Box bIn);

int main(){
    Box myBox1 = {"Gul",7,10,12}, myBox2={"Svart", 8, 11, 3};
    printBox(myBox1);
    printBox(myBox2);
    doubleHeight(&myBox2);
    printBox(myBox2);
    printBox(createBoxForBoxes(myBox1,myBox2));
    printf("%d\n",fit(myBox1,myBox2));
    return 0;
}

int fit(Box bOut, Box bIn){
    if(bOut.width>bIn.width){
        if((bOut.depth>bIn.depth&&bOut.height>bIn.height)||(bOut.depth>bIn.height&&bOut.height>bIn.depth))
            return 1;
    }
    if(bOut.width>bIn.depth){
        if((bOut.depth>bIn.width&&bOut.height>bIn.height)||(bOut.depth>bIn.height&&bOut.height>bIn.width))
            return 1;
    }
    if(bOut.width>bIn.height){
        if((bOut.depth>bIn.depth&&bOut.height>bIn.width)||(bOut.depth>bIn.width&&bOut.height>bIn.depth))
            return 1;
    }
    return 0;
}

Box createBoxForBoxes(Box b1, Box b2){
    Box b;
    strcpy(b.colour,"Vit");
    b.width=max(b1.width,b2.width);
    b.depth=max(b1.depth,b2.depth);
    b.height=b1.height+b2.height;
    return b;
}

int max(int a, int b){
    if(a>b) return a;
    return b;
}

void doubleHeight(Box *pBox){
    pBox->height*=2;
}

void printBox(Box b){
    printf ("%s %d*%d*%d\n",b.colour,b.width,b.depth,b.height);
}
