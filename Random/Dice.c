#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 7

int getNrOfDice();
void createFreqTable(int freq[], int amountOfThrows); // no * for array because it is a void and not a int
void fillWithZeros(int v[], int n);
void printArray(int v[], int n);
int throwDice();
int main()
{
    int nrOfThrows;
    int freqTable[SIZE]; 

    nrOfThrows = getNrOfDice();
    createFreqTable(freqTable, nrOfThrows);    // out parameter = freqTable  in parameter = nrOfThrows 
    
    //printFreqTable(freqTable, SIZE);

    
   return 0;
}

void createFreqTable(int freq[], int amountOfThrows)
{
    int result;
    fillWithZeros(freq, SIZE);
    for(int i = 0; i < amountOfThrows; i++)
    {
        result = throwDice();
        freq[result]++;
    } 
}

void fillWithZeros(int v[], int n)
{
    for(int i=0; i < n; i++)
    {
        printf("%d,", v[i]);
    }
    printf("\n");

}

int getNrOfDice()
{
    int amountOfThrows;
    printf("Enter the amount of dice(s) you wont thrown: ");
    scanf("%d", &amountOfThrows);
    printf("%d", amountOfThrows);

    return amountOfThrows;
}