#include <stdio.h>

int stringCount(char str[]);

int main()
{
    char str[20];
    gets(str);

    printf("Length: %d", stringCount(str));
    return 0;
}

int stringCount(char str[])
{
    int length;

    for(int i = 1; str[i] != '\0';i++)
    {
        length++;
    }
    return length;
}