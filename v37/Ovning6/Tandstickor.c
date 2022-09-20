#include <stdio.h>

int main()
{
    int spelaren, datorn, tot;

    tot = 15;
    
    printf("Valkommen till tandsticksspelet.\n|||||||||||||||\n");



    while (tot>0)
    {   
        printf("Hur manga stickor vill du ta? (1-3) ");
        scanf("%d",&spelaren);

        tot = tot - spelaren;
        for ( int i = 1; i <=tot ; i++)
        {
            printf("|");
        }
    
        printf("\n");
        
        if (tot == 0)
        {
            printf("Du vann!");
        }
        else
        {
            if (tot>3)
            { 
                datorn = 4 - spelaren;
                tot = tot - datorn;

                printf("Datorn tar %d stickor.\n", datorn);

                for ( int j = 1; j <=tot ; j++)
                {
                    printf("|");
                }
                
                printf("\n");
            }
            else
            {
                datorn = tot;

                printf("Datorn tar %d stickor.\n", datorn);
                printf("Dator vann!");

                tot = 0;
            }
        }
        
       
    }
    
    return 0;
}