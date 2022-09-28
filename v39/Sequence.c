#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getSize();
void view(int size, int arr[]);
void fillZeros(int size, int arr[]);
void getRandomNum(int size, int arr[]);

int main()
{
    int size;
    srand(time(0));
    size = getSize();
    int arr[size];
    fillZeros(size, arr);
    getRandomNum(size, arr);
    view(size, arr);
}

int getSize()
{
    int size = 0;
    while (size > 10000 || size < 1)
    {
        printf("Vilket ar det hogsta heltal du vill ha med (1-10000): ");
        scanf("%i", &size);

        if (size > 10000 || size < 1)
        {
            printf("Du maste valja mellan 1 och 10000! \n");
        }
    }
    return size;
}

void view(int size, int arr[])
{
    for (int i = 0; i < size; i++)
    {
        printf("%i, ", arr[i]);
    }
}

void getRandomNum(int size, int arr[])
{
    int isNumberSeen;
    int randomNum;

    for (int i = 0; i < size; i++)
    {
        isNumberSeen = 0;
        randomNum = rand() % size + 1;

        for (int j = 0; j < size; j++) 
        {
            if (arr[j] == randomNum) 
            {
                isNumberSeen = 1;
                i--;
            }
        }
        if(!isNumberSeen)
        {
            arr[i] = randomNum;
        }
    }
}

void fillZeros(int size, int arr[])
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = 0;
    }
}