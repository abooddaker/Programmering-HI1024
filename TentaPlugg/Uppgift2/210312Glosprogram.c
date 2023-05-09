#include <stdio.h>
#include <string.h>
#define MAX 20

int main(void)
{
    int menuChoice, nrOfWords;
    char registry[MAX][MAX];
    int character; 
    
    do
    {
        printf("(1) Skriva in (2) Skriva ut (3) Radera (4) Avsluta");
        printf("V„lj: value\n");
        scanf("%d", &menuChoice);

        switch(menuChoice)
        {
            case 1: // test
            break;
            case 2: 
            break;
            case 3: 
            break;

        }
    }while(menuChoice != 4);
}   

void registerWords(char registry[][MAX], int *pNrOfWords)
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
}