#include <stdio.h>

int main(void)
{
    int points = 1, money_spent = 0, input;

    printf("Malet „r 69 po„ng\n");

    while(points < 69)
    {
        printf("Du har %d po„ng. Vill du betala 5 eller 10 kr?: ", points);
        scanf("%d", &input);
        if (input == 5)
        {
            points += 4;
            money_spent += input;
        }
        if (input == 10)
        {
            points *= 3;
            money_spent += input;
        }
    }
    if(points == 69)
    {
        printf("Grattis du fick %d po„ng. Du anv„nde %d kr.", points, money_spent);
    }
    else 
    {
        printf("Du fick %d po„ng vilket „r f”r mycket. Du anv„nde %d kr.", points, money_spent);
    }
}