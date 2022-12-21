#include <stdio.h>
#include <string.h>
#define MAX 20

struct glosprogram 
{
    char english[MAX];
    char swedish[MAX];
};  typedef struct glosprogram Words;

void addWordPair(Words wordPairs[], int *pNrOfWordPairs);
void printAll(Words w[], int nrOfWordPairs);

int main(void)
{
    int menuChoice, nrOfWordPairs = 0;
    Words wordPairs[MAX];

    do
    {
        printf("(1) Skriva in (2) Skriva ut (3) Radera (4) Avsluta: ");
        scanf("%d", &menuChoice);

        switch(menuChoice)
        {
            case 1: addWordPair(wordPairs,&nrOfWordPairs);
            break;
            case 2: printAll(wordPairs,nrOfWordPairs);
            break;
            case 3: if(nrOfWordPairs == 0)
            {
                printf("Gloslistan „r redan tomt.\n");
                break;
            }
            else
            {
                nrOfWordPairs = 0;
                printf("Gloslistan raderades.\n");
                break;
            }

        }
    }while(menuChoice != 4);
}   

void addWordPair(Words wordPairs[], int *pNrOfWordPairs)
{
    if((*pNrOfWordPairs) >= MAX)
    {
        printf("Gloslistan „r fullt.\n");
        return;
    }
    while((*pNrOfWordPairs <= MAX))
    {
        printf("Svenska: ");
        scanf(" %s", wordPairs[*pNrOfWordPairs].swedish);
        if(strcmp(wordPairs[*pNrOfWordPairs].swedish,"q") == 0)
        {
            return;
        }
        printf("Engelska: ");
        scanf(" %s", wordPairs[*pNrOfWordPairs].english);
        (*pNrOfWordPairs)++;
    } 
}

void printAll(Words w[], int nrOfWordPairs)
{
    if(nrOfWordPairs == 0)
    {
        printf("Gloslistan „r tom.\n");
        return;
    }
    for(int i = 0; i < nrOfWordPairs; i++)
    {
        printf("Svenska: %s\n", w[i].swedish);
        printf("Engelska: %s\n", w[i].english);
    }
}


















/*void registerWords(char registry[][MAX], int *pNrOfWords)
{
    char swedish[MAX], english[MAX];
    if((*pNrOfWords) == MAX)
    {
        printf("Gloslistan „r fullt.");
        return;
    }
    for(int i = 0; i < *pNrOfWords; i++)
    {
        do
        {
            printf("Svenska: ");
            scanf(" %s%*c", swedish[i]);
            printf("Engelska: ");
            scanf(" %s%*c", english[i]);
            (*pNrOfWords)++;
            strcpy(registry[i], swedish[i]);
            strcpy(registry[i], english[i]);
        }while(swedish[i] != 'j');
    }
} */