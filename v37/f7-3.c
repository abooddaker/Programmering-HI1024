#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int arrayFill(int *array,int size)
{
    int lower = -10, upper = 10;

    srand(time(0));
    printf("Funktion 2: Fyller arrayn med slumptal mellan -10 och 10"); // funktion 2

    for(int i = 0; i < size; i++)
    {
        int randomN = (rand() % (upper - lower + 1)) + lower;
        array[i] = randomN;
        printf("%d", array[i]);
    }
}

int main(void)
{
    int size;
    printf("Enter array size: ");
    scanf("%d", &size);
    int array[size];
    arrayFill(array , size);
}




