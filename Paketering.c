#include <stdio.h>
#define MAXGOODS 100

int getData(int goods[], int nrOfGoods, int nrOfBoxes);

int main()
{
    int sizeOfBox, nrOfGoods, nrOfBoxes;
    int goods[MAXGOODS];

    getData(goods, nrOfGoods, nrOfBoxes);

    return 0;
}

int getData(int goods[], int nrOfGoods, int nrOfBoxes)
{
    int boxSize, goodsSize;
    do
    {
        printf("Ange ladstorlek (1-10kg): ");
        scanf("%d", &boxSize);
        if(boxSize < 1 || boxSize > 10)
        {
            printf("Felaktig inmatning\n");
        }
    } while (boxSize < 1 || boxSize > 10);
    do
    {
        printf("Ange vara (1-%dkg) eller 0 for att avsluta: ", boxSize);
        scanf("%d", &goodsSize);
        if(goodsSize < 0 || goodsSize > boxSize)
        {
            printf("Felaktig inmatning\n");
        }
    } while(goodsSize != 0 && goodsSize < 100);

    return nrOfGoods, nrOfBoxes;
}

/*
void viewArray(int goods[], int nrOfGoods, int nrOfBoxes)
{
    for(int i = 0; )
}


*/
