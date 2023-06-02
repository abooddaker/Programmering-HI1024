#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));
    int user_input, nrOfLetters, operations = 0;

    do
    {
        printf("Hur m†nga bokstaver vill du sortera? (2-20)? ");
        printf("Hur m†nga bokstaver vill du sortera? (2-20)? ");
        scanf("%d", &nrOfLetters);

    } while (nrOfLetters < 2 || nrOfLetters > 20);
    
    char letterArray[nrOfLetters];
}