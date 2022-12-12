#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 6

void shuffle(int cards[], int size);
void shuffle2(char letters[], int size);

int main()
{
    char letters[SIZE] = {'A','A','B','B','C','C'};
    int cards[SIZE];

    for (int j = 0; j < SIZE; j++)
    {
        cards[j] = j + 1; 
        printf("%d, ", cards[j]);
    }
    srand(time(0));

    shuffle(cards, SIZE);
    shuffle2(letters, SIZE);
    printf("\n");

    for (int j = 0; j < SIZE; j++)
    {
        //printf("%d, ", cards[j]);
        printf("%c, ", letters[j]);

    }
    return 0;
}

void shuffle(int cards[], int size)
{
        for (int i = 0; i < SIZE; i++)  
    {  
        int num = rand() % SIZE;
        int temp = cards[i];
        cards[i] = cards[num];
        cards[num] = temp;
    }

}

void shuffle2(char letters[], int size)
{
        for (int i = 0; i < SIZE; i++)  
    {  
        int num = rand() % SIZE;
        int temp = letters[i];
        letters[i] = letters[num];
        letters[num] = temp;
    }
}
