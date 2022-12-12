#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int arrayFill ( int *array ,int size)
{
    int lowestNumber = -10, highestNumber = 10;
    srand(time(0));
    for(int i = 0; i < size; i++)
    {
        int randomN = (rand() % (highestNumber - lowestNumber + 1)) + lowestNumber;
        array[i] = randomN;
    }
}

int arrayShow (int *array ,int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
}

int arraySort (int *array ,int size)
{
    int j, arraySort;
    for(int i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            if(array[j] > array[j+1])
            {
                arraySort = array[j];
                array[j] = array[j+1];
                array[j+1] = arraySort;            
            }
        }
    }
}
int main(void)
{
    int size;
    printf("Enter your array size: ");
    scanf("%d", &size);
    int array[size];
    arrayFill(array, size);
    printf("Unsorted randomly generated numbers: ");
    arrayShow(array, size);
    arraySort(array, size);
    printf("Sorted randomly generated numbers:  ");
    arrayShow(array, size);

    return 0;
}