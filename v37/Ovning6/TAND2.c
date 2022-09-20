#include <stdio.h>

int main()
{
    int computer, player, totalMatches; 
    
    printf("Valkommen till tandsticksspelet. \n||||||||||||||| \n");

    totalMatches = 15;

    while (totalMatches > 0)
    {
        printf("Hur manga stickor vill du ta? (1-3) ");
        scanf("%d", &player);

        if (player < 1 || 3 < player)
        {
            printf("Pick a number between (1-3): \n");
            scanf("%d", &player);
        }
        else
        {
            totalMatches = totalMatches - player;
            for (int i = 1; i <= totalMatches; i++)
            {
                printf("|");
            }
            
                printf("\n");
        }
        if (totalMatches == 0)
        {
            printf("Gratz! you won!");
        }
        else if (totalMatches > 3)
        {
            computer = 4 - player;
            totalMatches = totalMatches - computer;

            printf("The computer took %d matche(s)\n", computer);

            for (int x = 1; x <= totalMatches ; x++)
                {
                    printf("|");
                }
            
            printf("\n");
        } 
        else 
        {
            computer = totalMatches;
            printf("Computer takes %d matche(s)a\n", computer);
            printf("Computer won!");
            totalMatches = 0;
        }


    }
    return 0;
}