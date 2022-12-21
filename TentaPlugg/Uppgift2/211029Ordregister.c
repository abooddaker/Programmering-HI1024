#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10
#define WORDLENGTH 31

void registerWord(char dictionary[][WORDLENGTH],int *pNrOfWords);
void printWords(char dictionary[][WORDLENGTH], int pNrOfWords);
void deleteWord(char dictionary[][WORDLENGTH], int *pNrOfWords);
void shuffleWords(char dictionary[][WORDLENGTH], int *pNrOfWords);



int main(void)
{
    int menuChoice, nrOfWords = 0;
    char dictionary[MAX][WORDLENGTH];

    do
    {
        printf("(1) Registrera (2) Skriva ut alla (3) Radera (4) Blanda (5) Vanligaste (6) Avsluta. (1-6): ");
        scanf("%d%*c", &menuChoice);
        if(menuChoice > 6 || menuChoice <= 0)
        printf("Invalid input, f”rs”k igen (1-6)\n");
        else
        {
            switch(menuChoice)
            {
                case 1: registerWord(dictionary,&nrOfWords); //regisrera nya ord printf()
                break;
                case 2: printWords(dictionary,nrOfWords); // skriva ut alla
                break; 
                case 3: deleteWord(dictionary, &nrOfWords);// radera ord
                break;
                case 4: shuffleWords(dictionary, &nrOfWords);
                break;
                case 5: 
                break;
            }
        }
    } while(menuChoice != 6);
    printf("Avslutar");
}

void registerWord(char dictionary[][WORDLENGTH], int *pNrOfWords)
{
    char stop;
    if((*pNrOfWords) >= MAX)
    {
        printf("Registret full.\n");
        return;
    }
    else
    {
        printf("Ange ord: ");
        scanf("%s%*c", dictionary[*pNrOfWords]);
        (*pNrOfWords)++;
    }
}

void printWords(char dictionary[][WORDLENGTH], int pNrOfWords)
{
    if(pNrOfWords == 0)
    {
        printf("Registret tomt.");
    }
    for(int i = 0; i < pNrOfWords; i++)
    {
        printf("%s, ", dictionary[i]);
    }
    printf("\n");
}

void deleteWord(char dictionary[][WORDLENGTH], int *pNrOfWords)
{
    int deleteInput;

    printf("Ange ordningsnummer att radera: ");
    scanf("%d", &deleteInput);
    if(deleteInput > (*pNrOfWords))
    {
        printf("Felaktig nummer.\n");
        return;
    }  

    for(int i = deleteInput-1; i < (*pNrOfWords-1); i++)
    {
        strcpy(dictionary[i],dictionary[i+1]);
    }
    (*pNrOfWords)--; 
}

void shuffleWords(char dictionary[][WORDLENGTH], int *pNrOfWords)
{
    srand(time(NULL));
    int j;

    for(int i = 0; i < (*pNrOfWords); i++)
    {
        j = rand() % (*pNrOfWords);
        char temp[WORDLENGTH];
        strcpy(temp, dictionary[i]);
        strcpy(dictionary[i], dictionary[j]);
        strcpy(dictionary[j], temp);
    }
}
