#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//find out how many words are there in the string

// int stringCount(char str[]);

int main()
{
    char str[50];
    printf("Please enter a sentence: ");
    gets(str);
    int count = 0;
    
    for(int i = 0; i < strlen(str); i++)
    {
        if(str[i] == ' ')
        count++;
    }
    printf("%d", strlen(str));
    printf("Amount of words: %d", count + 1);
    

    
    return 0;
}
/*
int stringCount(char str[])
{
    int length;

    for(int i = 1; str[i] != '\0';i++)
    {
        length++;
    }
    return length;
}
*/