#include <stdio.h>
#define MAXNROFGOODS 100
#define MAXBOXSIZE 10

void printArray(int v[],int n);
void getInData(int goods[],int *boxSize, int *nrOfGoods);
int neededNrBoxes(int goods[],int boxSize,int nrOfGoods);
void printResult(int goods[],int nrOfGoods,int nrOfBoxes);
int main(){
    int boxSize, nrOfGoods=0,nrOfBoxes;
    int goods[MAXNROFGOODS];

    getInData(goods,&boxSize,&nrOfGoods);
    nrOfBoxes = neededNrBoxes(goods,boxSize,nrOfGoods);
    printResult(goods,nrOfGoods,nrOfBoxes);

    return 0;
}

void printResult(int goods[],int nrOfGoods,int nrOfBoxes)
{
    printf("Varorna (");
    for(int i=0;i<nrOfGoods-1;i++) printf("%d, ",goods[i]);
    printf("%d) kan packas i %d lador.\n",goods[nrOfGoods-1],nrOfBoxes);
}

int neededNrBoxes(int goods[],int boxSize,int nrOfGoods)
{
    int nrOfBoxes=1,currentFill=0;
    for(int i=0;i<nrOfGoods;i++)
    {
        if(currentFill+goods[i]<=boxSize)
        {
            currentFill+=goods[i];
        }else{
            nrOfBoxes++;
            currentFill=goods[i];
        }
    }
    return nrOfBoxes;
}

void getInData(int goods[],int *pBoxSize, int *pNrOfGoods)
{
    int goodSize;
    do
    {
        printf("Ange ladstorlek (1-10kg): ");
        scanf("%d",pBoxSize);
        if(*pBoxSize<1||*pBoxSize>MAXBOXSIZE) printf("Felaktig inmatning\n");
    }while(*pBoxSize<1||*pBoxSize>MAXBOXSIZE);
    do
    {
        printf("Ange vara (1-%dkg) eller 0 for att avsluta: ",*pBoxSize);
        scanf("%d",&goodSize);
        if(goodSize<0||goodSize>*pBoxSize)
        {
            printf("Felaktig inmatning\n");
        }
        else if(goodSize!=0)
        {
            goods[*pNrOfGoods]=goodSize;
            (*pNrOfGoods)++;
        }
    }while(goodSize!=0 && *pNrOfGoods<MAXNROFGOODS);

}

void printArray(int v[],int n){
    for(int i=0;i<n;i++) printf("%d ",v[i]);
    printf("\n");
}