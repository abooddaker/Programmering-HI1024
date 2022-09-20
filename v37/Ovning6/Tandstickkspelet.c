#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    
    srand(time(0));

    int number1Dator = (rand() % 3) + 1;
    int total = 15;
    int player;

    printf("Valkommen till tandsticksspelet. \n ||||||||||||||| \n");
    
    
    while(total > 1)
    {
        printf("Hur manga stickor vill du ta? (1-3) ");
        scanf("%d", &player);

        if(player < 1 || 3 < player)
        {
            printf("Pls only choose a number between (1-3): \n");
        }
        else
        {
            total = total - player;
            
            for (int i = 1 ; i <= total; i++)
            {
                printf("|");
            }

            printf("\nDatorn valde %d stickor\n", number1Dator);
            total = total - number1Dator;
            printf("Stickor kvar: %d\n", total);
        }

        
    }

    return 0;

}