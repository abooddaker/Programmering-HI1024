#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(0));
    int coinflip, input, nrOfGuesses = 0;

    while(1)
    {
        coinflip = rand() % 2 + 1;
        printf("%d\n", coinflip);

        printf("Vill du satsa pa krona (1) eller klave (2): ");
        scanf("%d", &input);

        if(coinflip == 1)
        {
            printf("Det blev krona.\n");
            nrOfGuesses++;
        }
        else 
        {
            printf("Det blev klave.\n");
            nrOfGuesses++;
        }
        if(coinflip != input)
        {
            break;
        }
    }
    if(nrOfGuesses == 2)
    {
        printf("Du gissade r„tt %d g†ng\n", nrOfGuesses-1);
    }
    else if(nrOfGuesses == 1)
    {
        printf("Du aldrig gissade r„tt.");
    }
    else
    {
        printf("Du gissade r„tt %d g†nger\n", nrOfGuesses-1);
    }
}