#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillCharArray(char letterArray[], int nrOfLetters);
void fillIndexArray(int indexArray[], int nrOfLetters);
void printCharArray(char letterArray[], int nrOfLetters);
void printIndexArray(int indexArray[], int nrOfLetters);
void swap(char letterArray[], int i, int j);
int checkIfSorted(char letterArray[], int nrOfLetters);
void fill2ndArray(char arr1[],char arr2[], int nrOfLetters);
void sortArray(char arr1[], int nrOfLetters);
int compareArray(char arr1[], char arr2[], int nrOfLetters);



int main(void)
{
    srand(time(NULL));
    int user_input, nrOfLetters, operations = 0;

    do
    {
        printf("Hur m†nga bokstaver vill du sortera? (2-20)? ");
        scanf("%d", &nrOfLetters);

    } while (nrOfLetters < 2 || nrOfLetters > 20);
    
    char letterArray[nrOfLetters];
    char arr[nrOfLetters];
    int indexArray[nrOfLetters];

    fillCharArray(letterArray, nrOfLetters);
    fill2ndArray(arr,letterArray, nrOfLetters);
    sortArray(arr,nrOfLetters);
    printCharArray(arr,nrOfLetters);
    printf("\n");
    fillIndexArray(indexArray, nrOfLetters);
    printIndexArray(indexArray, nrOfLetters);
    printCharArray(letterArray, nrOfLetters);

    while(1)
    {
        /*if(checkIfSorted(letterArray, nrOfLetters) == 1)
        {
            break;
        }*/
        if(compareArray(arr,letterArray,nrOfLetters) == 1)
        {
            break;
        }
        printf("Var vill du byta plats ");
        scanf("%d", &user_input); 
        if(user_input >= nrOfLetters || user_input <= 0 || user_input == nrOfLetters)
        {
            printf("Felaktig val\n");
        }
        else
        {
            swap(letterArray,user_input-1,user_input);
            printIndexArray(indexArray, nrOfLetters);
            printCharArray(letterArray, nrOfLetters);
            operations++;
        }

    }
    printf("KLART! Du gjorde %d byten.", operations);
}

int compareArray(char arr1[], char arr2[], int nrOfLetters)
{
    int count = 0;

    for(int i = 0; i < nrOfLetters; i++)
    {
        if(arr1[i] == arr2[i])
        {
            //printf("%d,%d", arr1[i], arr2[i]);
            count++;
        }
    }

    if(count == nrOfLetters)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void sortArray(char arr1[], int nrOfLetters)
{
    for(int i = 0; i < nrOfLetters-1; i++)
    {
        for(int j = 0; j < nrOfLetters-i-1; j++)
        {
            if(arr1[j] > arr1[j+1])
            {
                swap(arr1,j,j+1);
            }
        }
    }
}

void fill2ndArray(char arr1[],char arr2[], int nrOfLetters)
{
    for(int i = 0; i < nrOfLetters; i++)
    {
        arr1[i] = arr2[i];
    }
}

/*int checkIfSorted(char letterArray[], int nrOfLetters)
{
    for(int i = 0; i < nrOfLetters; i++)
    {
        if(letterArray[i] > letterArray[i+1])
        {
            return 0;
        }
    }
    return 1;
}*/

void fillIndexArray(int indexArray[], int nrOfLetters)
{
    for(int i = 0; i < nrOfLetters; i++)
    {
        indexArray[i] = i + 1;
    }
}

void fillCharArray(char letterArray[], int nrOfLetters)
{
    for(int i = 0; i < nrOfLetters; i++)
    {
        letterArray[i] = rand() % 26 + 'A';
    }
}

void printCharArray(char letterArray[], int nrOfLetters)
{
    for (int i = 1; i < nrOfLetters+1; i++)
    {
        printf("%d ", i);
    }
    for(int i = 0; i < nrOfLetters; i++)
    {
        printf("%c ", letterArray[i]);
    }
    printf("\n");
}

void printIndexArray(int indexArray[], int nrOfLetters)
{
    for(int i = 0; i < nrOfLetters; i++)
    {
        printf("%d ", indexArray[i]);
    }
    printf("\n");
}

void swap(char letterArray[], int i, int j)
{
    char tmp = letterArray[i];
    letterArray[i] = letterArray[j];
    letterArray[j] = tmp;
}