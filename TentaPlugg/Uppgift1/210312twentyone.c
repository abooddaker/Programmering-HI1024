#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
    int card, points, randomCard, total = 0;
    char stop;
    srand(time(0));
    do
    {   
        randomCard = rand() % 13 + 1;
        total += randomCard;
        printf("Du fick %d och har summa %d.\n", randomCard, total);
        if(total >= 22)
        {
            points = 0;
            printf("Result: %d", points);
            break;
        }
        printf("Vill du ha ett kort till? (j/n): ");
        scanf(" %c", &stop);
        if(stop == 'n')
        {
            if(total <= 17)
            {
                points = 1;
                printf("Resultat: %d", points);
                break;
            } 
            if(total > 17 && total < 21)
            {
                points = 2;
                printf("Resultat: %d", points);
                break;
            }
            if(total == 21)
            {
                points = 3;
                printf("Resultat: %d", points);
                break;
            }
            break;
        }

    } while(1 || points <= 21);

    return 0;

}