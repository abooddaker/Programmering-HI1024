#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main(void)
{
    int shuffledArray[10], num;
    float temp;

    for(int i = 0; i < 10; i++)
    {
        shuffledArray[i] = (float) rand() / RAND_MAX * 0.99;
    }

    for(int i = 0; i < 10; i++)
    {
        printf("%d ", shuffledArray[i]);
    }

    printf("\n");
    srand(time(NULL));

    for(int i = 0; i < 10; i++)
    {
        num = rand() % 10 + 1;
        temp = shuffledArray[i];
        shuffledArray[i] = shuffledArray[num];
        shuffledArray[num] = temp;
    }

    for(int i = 0; i < 10; i++)
    {
        printf("%d ", shuffledArray[i]);
    }


}