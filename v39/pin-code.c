#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SOZE 3

int randomPin(int randomCode[], int userCode[]);

int main()
{
    int randomCode[SOZE];
    int userCode[SOZE];
    
    srand(time(0));
    randomPin(randomCode, userCode);

    return 0;
}

int randomPin(int randomCode[], int userCode[])
{
    int attempts = 0, CorrectNumbers = 0, nrOfCorrectGuesses = 0;

    for(int i = 0; i < SOZE; i++)
    {
        randomCode[i] = rand() % 9;
        printf("%d ", randomCode[i]);
    }
    while(CorrectNumbers == 0)
    {
        int nrOfCorrectGuesses = 0;
        attempts++;
        printf("\nGuess the code: \n");
        scanf("%d %d %d", &userCode[0], &userCode[1], &userCode[2]);

        for(int i = 0; i < SOZE; i++)
        {
            for(int j = 0; j < SOZE; j++)
            {
                if(randomCode[i] == userCode[i])
                {
                    nrOfCorrectGuesses++;
                    break;
                }
            }
        }
        if (nrOfCorrectGuesses == 3)
        {
            CorrectNumbers = 1;
            printf("Correct pin code! You needed %d attempts. ", attempts);
            break; 
        }
        printf("Wrong pin code! you had %d correct numbers", nrOfCorrectGuesses);
    }
}