#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
    int card, points = 0, randomCard, total = 0;
    char stop;
    srand(time(0));
    while(stop != 'n')
    {   
        randomCard = rand() % 13 + 1;
        total += randomCard;
        printf("Du fick %d och har summa %d\n", randomCard, total);
        if(total >= 21) break;
        printf("Vill du ha ett kort till (j/n): ");
        scanf(" %c", &stop);
    }

    if(total <= 17)
    {
        points = 1;
    }
    if(18 <= total && total <= 20)
    {
        points = 2;
    }
    if(total == 21)
    {
        points = 3;
    }
    printf("Resultat %d poang.", points);
}