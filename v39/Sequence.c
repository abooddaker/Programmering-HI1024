#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getSize();
void view(int size, int arr[]);
void getRandomNum(int size, int arr[]);

int main()
{
    int size;
    srand(time(0));
    size = getSize();
    int arr[size];
    getRandomNum(size, arr);
    view(size, arr);
}

int getSize()
{
    int size = 0;
    while (size > 10000 || size < 1)
    {
        printf("Vilket ar det hogsta heltal du vill ha med (1-10000): ");
        scanf("%d", &size);

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
        printf("%d, ", arr[i]);
    }
}

void getRandomNum(int size, int arr[])
{
    int numberSeen;
    int randomNum;

    for (int i = 0; i < size; i++)
    {
        numberSeen = 0;
        randomNum = rand() % size + 1;

        for (int j = 0; j < size; j++) 
        {
            if (arr[j] == randomNum) 
            {
                numberSeen = 1;
                i--;
            }
        }
        if(!numberSeen)
        {
            arr[i] = randomNum;
        }
    }
}

/*void fillZeros(int size, int arr[])
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = 0;
    }
}
*/