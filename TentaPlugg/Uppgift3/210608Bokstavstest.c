#include <stdio.h>
#include <string.h>
#define MAXCHAR 21

int indexForMostA(char words[][MAXCHAR], int nrOfWords);

int main(void)
{
    char words[4][MAXCHAR] = {"BAAAAAAN","ARBETA","ADAPTERA","DATA"};
    int index = indexForMostA(words,4);


    printf("Amount of A's: %d\n", indexForMostA(words,4));
    printf("%s", words[index]);
}

int indexForMostA(char words[][MAXCHAR], int nrOfWords)
{
    int maxA = 0, nrOfA, index = -1;

    for(int i = 0; i < nrOfWords; i++)
    {
        nrOfA = 0;
        for(int j = 0; j < strlen(words[i]); j++)
        {
            if(words[i][j] == 'A')
            {
            nrOfA++;
            }
        }
        if (nrOfA > maxA)
        {
        maxA = nrOfA;
        index = i;
        }
    }
    return index;
}