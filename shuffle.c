#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 6

void shuffle(int cards[], int size);

int main()
{
    int cards[SIZE];

    for (int j = 0; j < SIZE; j++)
    {
        cards[j] = j + 1; 
        printf("%d, ", cards[j]);
    }
    srand(time(0));

    shuffle(cards, SIZE);
    printf("\n");

    for (int j = 0; j < SIZE; j++)
    {
        printf("%d, ", cards[j]);
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
