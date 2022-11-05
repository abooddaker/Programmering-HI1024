#include <stdio.h>
#include <stdbool.h> 
#include <string.h> 
#include <stdlib.h> 
#include <time.h>
 
#define MAX 10
 
void containsChar(int myChars[], char charToHide[], int length);
void view(char myChars[], int length);
void shuffle(char cards[], int length);
 
void main(void)
{
    srand((unsigned) time(0));
    unsigned char cards[MAX] = "AABBCCDDEE";
    unsigned int charsArr[] = { 1,2,3,4,5,6,7,8,9,10 };
    unsigned int charsToHide[MAX] = {0};
    unsigned int length = MAX, choice1, choice2, i = 0, tries = 0, amountOfPair = 0;;
 
    shuffle(cards, length);
 
    while (amountOfPair != MAX/2)
    {
        printf("Card: ");
        containsChar(charsArr, charsToHide, length);
        printf("Which can card do you want to flip : ");
        scanf_s(" %d %d", &choice1, &choice2);
 
        if (choice1 == choice2 || choice1 > MAX || choice2 > MAX || choice1 < 1 || choice2 < 1)
        {
 
            printf("Wrong input \n");
        }
        else
        {
            if (cards[choice1 - 1] == cards[choice2 - 1])
            {
                printf("You got a pair of %c \n", cards[choice1 - 1]);
                charsToHide[i] = choice1;
                charsToHide[i + 1] = choice2;
                i += 2;
                amountOfPair++;
            }
            else
            {
                printf("You got %c and %c \n", cards[choice1 - 1], cards[choice2 - 1]);
            }
        }
        tries++;
    }
 
    printf("amount of tries: %d", tries);
}
 
 
void containsChar(int myChars[], char charToHide[], int length)
{
    int isEqual;
    for (int i = 0; i < length; i++)
    {
        isEqual = 0;
        for (int j = 0; j < 40; j++)
        {
            if (myChars[i] == charToHide[j])
            {
                isEqual = 1;
            }
        }
        if (isEqual == 0)
        {
            printf("%d", myChars[i]);
        }
    }
    printf("\n");
}
 
void view(char cards[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%c", cards[i]);
    }
    printf("\n");
}
 
void shuffle(char cards[], int length)
{
    for (int i = 0; i < length; i++)
    {
        int temp_index = rand() % length;
        char temp = cards[i];
        cards[i] = cards[temp_index];
        cards[temp_index] = temp;
    }
}