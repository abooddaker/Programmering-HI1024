#include <stdio.h>


int main(void)
{   
    int sides_in_cm, sides_in_m;
    float amount = 0;
    char stop;

    while(1)
    {
        printf("Ange plattornas sida i cm: ");
        scanf("%d", &sides_in_cm);
        printf("Vilken langd i m har din gang? ");
        scanf("%d", &sides_in_m);

        sides_in_m *= 100;
        amount = (float) sides_in_m / sides_in_cm;

        //printf("%d, %d\n", sides_in_cm, sides_in_m);
        printf("Current amount: %f\n", amount); // <- so important debugging. 

        if(amount != (int) amount)
        {
            amount++;
        }
        printf("Du beh”ver %d plattor.\n", (int) amount);

        printf("Vill du avsluta? (j/n): ");
        scanf(" %c", &stop);
        if(stop == 'j') // ASSIGNMENT OPERATOR ISN'T THE SAME AS COMPARISON OPERATOR!!!!! !! !! ! !  !
        {
            break;
        }
    }
}