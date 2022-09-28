#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 3

int main()
{
    srand(time(NULL));
    
    int guess, number[SIZE], numberOfGuesses;

    int i = 0;
    for(int i = 0; i < SIZE; i++);
    {
        number[i] = rand() % 9;
        printf("%d", number[i]);
    }
}