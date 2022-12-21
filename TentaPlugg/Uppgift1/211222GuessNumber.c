#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void)
{
    int random_number, user_number, nrOfGuesses = 0;
    srand(time(NULL));
    random_number = rand() % 1000+1;
    printf("%d\n", random_number);

    while(1)
    {   
        printf("Gissa ett tal mellan 1 och 1000: ");
        scanf("%d", &user_number);
        nrOfGuesses++;

        if(user_number == random_number)
        {
            break;
        }
        else if(user_number > random_number)
        {
            printf("F”r stor\n");
        }
        else if(user_number < random_number)
        {
            printf("F”r liten\n");
        }
    }
    
    printf("Korrekt. Du klarade det pa %d gissningar.", nrOfGuesses);

}