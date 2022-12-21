#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NRCARDS 10 //have to be even

void initiateCards(char cards[],int nrOfCards);
void printArray(char a[], int length);
void shuffleArray(char a[], int length);
void swap(char a[], int i, int j);
void printAvailable(char cards[], int length);
void playGame(char cards[],int nrOfCards);

int main(){
    char cards[NRCARDS];//'-' for taken
    srand(time(NULL));
    initiateCards(cards,NRCARDS);
    //printArray(cards,NRCARDS);
    playGame(cards,NRCARDS);
    return 0;
}

void playGame(char cards[],int nrOfCards)
{
    int cardsLeft = nrOfCards;
    int card1, card2, nrTurns=0;
    while(cardsLeft>0){
        printAvailable(cards,nrOfCards);
        printf("Vilka kort vill du vanda? ");
        scanf("%d %d",&card1,&card2);
        card1--;
        card2--;
        if(card1<0 || card1>=nrOfCards || card2<0 || card2>=nrOfCards || cards[card1]=='-' || cards[card2]=='-' || card1 == card2)
        {
            printf("Felaktigt val\n");
        }
        else if(cards[card1]==cards[card2])
        {
            printf("Du fick paret %c\n",cards[card1]);
            cardsLeft-=2;
            nrTurns++;
            cards[card1]=cards[card2]='-';
        }
        else
        {
            printf("Du fick %c och %c\n",cards[card1],cards[card2]);
            nrTurns++;
        }
    }
    printf("Du anvande %d turer\n",nrTurns);
}

void printAvailable(char cards[], int length)
{
    printf("Kort: ");
    for(int i=0;i<length;i++)
    {
        if(cards[i]!='-') printf("%d, ",i+1);
    }
    printf("\n");
}

void shuffleArray(char a[], int length)
{
    int pos;
    char tmp;
    for(int i=0;i<length;i++)
    {
        swap(a,i,rand()%length);
    }
}

void swap(char a[], int i, int j)
{
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;    
}

void printArray(char a[], int length)
{
    for(int i=0;i<length;i++)
    {
        printf("%c, ",a[i]);
    }
    printf("\n");
}

void initiateCards(char cards[],int nrOfCards)
{
    for(int i=0;i<nrOfCards/2;i++)
    {
        cards[i]=cards[nrOfCards/2+i]='A'+i;
    }
    shuffleArray(cards,nrOfCards);
}