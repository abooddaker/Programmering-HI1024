#include <stdio.h>

int stringCount(char string[]);

int main(void)
{
    
    char words[] = "Kungliga Tekniska Hogskola";
    //char words[100];
    
    //printf("Enter a word: ");
    //scanf("%s", words);
    printf("Length of string: %d\n", stringCount(words));

    return 0;
}

int stringCount(char string[])
{
    int length = 0;
    for (int i = 0; string[i] != '\0'; i++)
    {
        length++;
    }
    return length;
}
