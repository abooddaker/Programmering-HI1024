#include <stdio.h>

int main()
{

    char firstName[10];
    
    gets(firstName);
    printf("%s", firstName);
    //puts(firstName);   // both of them work but printf gives more freedom

    return 0;
}