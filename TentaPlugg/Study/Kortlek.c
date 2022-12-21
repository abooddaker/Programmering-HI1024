#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DECKSIZE 52 //obs går ej att byta

struct card{
    int value;
    char colour;
};
typedef struct card Card;

void drawAndEvaluateHand(int nrOfCards);
void fill(Card deck[]);
void mix(Card deck[]);
void printCard(Card c);
void printHand(Card deck[],int nrOfCards);
void swap(Card deck[],int p1, int p2);
int straight(Card deck[], int nrOfCards);
void sort(Card deck[], int nrOfCards);

int main()
{
    int nrOfCards=-1;

    srand(time(NULL));
    while(nrOfCards!=0)
    {
        printf("Hur manga kort vill du dra (0-10): ");
        scanf("%d",&nrOfCards);
        if(0<nrOfCards&&nrOfCards<=10)
        {
            drawAndEvaluateHand(nrOfCards);
        }
    }
    printf("Avslutar\n");
    return 0;
}

void drawAndEvaluateHand(int nrOfCards)
{

    Card deck[DECKSIZE];
    fill(deck);
    mix(deck);
    printHand(deck,nrOfCards);
    sort(deck,nrOfCards);
    if(straight(deck,nrOfCards))
        printf("Du fick stege\n");
}

int straight(Card deck[], int nrOfCards)
{
    sort(deck,nrOfCards);
    for(int i=0;i<nrOfCards-1;i++)
    {
        if(deck[i].value+1!=deck[i+1].value)
            return 0;
    }
    return 1;
}

void sort(Card deck[], int nrOfCards)
{
    for(int i=0;i<nrOfCards-1;i++)
    {
        for(int j=0;j<nrOfCards-1-i;j++)
        {
            if(deck[j].value>deck[j+1].value)
            {
                swap(deck,j,j+1);
            }
        }
    }
}

void printHand(Card deck[],int nrOfCards)
{
    for(int i=0;i<nrOfCards;i++)
    {
        printCard(deck[i]);
        printf(", ");
    }
    printf("\n");
}

void mix(Card deck[])
{
    for(int i=0;i<DECKSIZE;i++)
    {
        swap(deck,i,rand()%DECKSIZE);
    }
}

void swap(Card deck[],int p1, int p2)
{
    Card tmp=deck[p1];
    deck[p1]=deck[p2];
    deck[p2]=tmp;
}

void fill(Card deck[])
{
    for(int i=0;i<DECKSIZE;i++)
    {
        if(i/13==0)
        {
            deck[i].value=i+1;
            deck[i].colour='S';
        }
        else if(i/13==1)
        {
            deck[i].value=i-13+1;
            deck[i].colour='H';
        }
        else if(i/13==2)
        {
            deck[i].value=i-26+1;
            deck[i].colour='K';
        }
        else
        {
            deck[i].value=i-39+1;
            deck[i].colour='R';
        }
    }
}

void printCard(Card c)
{
    printf("%d%c",c.value,c.colour);
}
