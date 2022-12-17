#include <stdio.h>
#define FOT_IN_METER 0.2969
#define ALN_IN_METER 0.594
#define FAMN_IN_METER 1.78

int main(void)
{
    float user_choice, user_length, length_in_meter;

    while(1)
    {
        printf("Ange en langd: ");
        scanf("%f", &user_length);

        if(user_length < 0.0001)
        {
        break;
        }
        printf("Ange enhet (1) famn, (2) aln, (3) fot: ");
        scanf("%f", &user_choice);

        if(user_choice == 1)
        {
            length_in_meter = user_length * FAMN_IN_METER; 
        }
        else if (user_choice == 2)
        {
            length_in_meter = user_length * ALN_IN_METER;
        }
        else if(user_choice == 3)
        {
            length_in_meter = user_length * FOT_IN_METER;
        }
        
        {
            printf("Ogiltig input");
        }
        printf("Det motsvarar: \n");
        printf("%.2f famn, %.2f aln, %.2f fot, %.2f meters\n", length_in_meter/FAMN_IN_METER, length_in_meter/ALN_IN_METER, length_in_meter/FOT_IN_METER, length_in_meter);
    } 
    printf("Avslutar");
}