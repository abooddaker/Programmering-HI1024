#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    int size;

    do
    {
        printf("Enter highest number: (1-10000): ");
        scanf("%d", &size);
    if (size < 1 || size > 10000)
    {
        printf("Please enter a number between 1 and 10000!\n");
    }
    else 
    {
        int randomArray[size];

        for(int i = 0; i < size; i++)
        {
            randomArray[i] = rand() % size + 1;
            printf("%d, ", randomArray[i]);
        }
    }
    } while (size < 1 || size > 10000 );

    return 0;    
}