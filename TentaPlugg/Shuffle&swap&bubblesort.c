#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

void printArray(int array[], int nrOfNumbers);
void swap(int array[], int n1, int n2);


int main(void)
{
    int nrOfNumbers = SIZE;
    int a, b, c, j, temp;
    int array[SIZE];

    srand(time(NULL));


    for(int i = 0; i < SIZE; i++)
    {
        array[i] = i+1;
    }

printf("Normal     array: ");
printArray(array,SIZE);

    for(int i = 0; i < SIZE; i++)
    {
        j = rand() % SIZE;
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

printf("\nRandomized array: ");
printArray(array,SIZE);

    for(int i = 0; i < SIZE-1; i++)
    {
        for(int j = 0; j < SIZE-1-i; j++)
        {
            if(array[j] > array[j+1])
            {
                swap(array, j, j+1);
                /*temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;*/
            }
        }
    }

printf("\nSorted array:     ");
printArray(array,SIZE);
}

void printArray(int array[], int nrOfNumbers)
{
    for(int i = 0; i < nrOfNumbers; i++)
    {
        printf("%d ", array[i]);
    }
}

void swap(int array[], int n1, int n2)
{
    int temp = array[n1];
    array[n1] = array [n2];
    array[n2] = temp;
}