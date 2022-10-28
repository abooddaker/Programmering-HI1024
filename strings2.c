#include <stdio.h>

int main()
{

    char firstName[10];
    
    gets(firstName);
    printf("%s", firstName);
    //puts(firstName);

    return 0;
}