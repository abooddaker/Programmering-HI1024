#include <stdio.h>

int main(void)
{
    float userLength, meter;
    int userChoice;

    while(1)
    {
        printf("Ange en langd: ");
        scanf("%f", &userLength);

        if(userLength > 0.0001)
        {
            break;
        } 
        else
        {
            printf("Ange enhet (1) famn, (2) aln, (3) fot: ");
            scanf("%d", &userChoice);
        }
        if(userChoice == 1)
        {
            userLength = userLength * 1.78;
            
        } 
        else if (userChoice == 2)
        {
            userLength = userLength * 0.594;
        }
        else if(userChoice == 3)
        {
            userLength = userLength * 0.2969;
        } 
        else
        {
            printf("Felaktig val\n");
        }

        printf("Famn: %.2f, Aln:  %.2f, fot: %.2f meter: %.2f\n", userLength/1.78, userLength/0.594, userLength/0.2969, userLength);
    }

    printf("Avslutar");
}