#include <stdio.h>

int main()
{
    char fullName[20];
    gets(fullName);

    printf("Your name is: ");
    puts(fullName); // or printf

    return 0;
}