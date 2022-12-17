#include <stdio.h>

int main(void)
{
    int code, choice;
    char character, check_stop;

    do 
    {
        printf("Vill du ange ett tecken (1) eller en kod (2): ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            printf("Ange tecken: ");
            scanf(" %c", &character);
            printf("Tecknet motsvaras av koden: %d\n", character);
        } 
        else
        {
            printf("Ange kod: ");
            scanf("%d", &code);
            if(code < 1 || code > 127)
            {
                printf("Du angav inte en ascii-kod.\n");
            } 
            else 
            {
                printf("Koden motsvaras av tecknet: %c \n", code);
            }
        }

        printf("Vill du avsluta? (j/n): ");
        scanf(" %c", &check_stop);

    } while(check_stop != 'j');

    printf("Avslutar!");

    return 0;
}