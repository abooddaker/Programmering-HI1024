#include <stdio.h>

int main(void)
{
    int ascii_code, menu_choice;
    char ascii_char, check_stop;
    
    do
    {
        printf("Vill du ange ett tecken (1) eller en kod (2): ");
        scanf("%d", &menu_choice);

        if(menu_choice == 1)
        {
            printf("Ange tecken: ");
            scanf(" %c", &ascii_char);
            printf("Koden motsvaras av tecknet: %d\n", ascii_char);
            printf("Tecknet motsvaras av koden: %c\n", ascii_char);
            printf("Tecknet motsvaras av koden: %d\n", ascii_char);
        }
        else
        {
            printf("Ange kod: ");
            scanf("%d", &ascii_code);

            if(ascii_code < 0 || ascii_code > 127)
            {
                printf("Du angav inte en ascii-kod.\n");
                printf("Tecknet motsvaras av koden: %c\n", ascii_code);
            } 
            else
            {
                printf("Tecknet motsvaras av koden: %c\n", ascii_code);
                printf("Tecknet motsvaras av koden: %d\n", ascii_code);
            }
        }
            printf("Vill du avsluta? (j/n): ");
            scanf(" %c", &check_stop);

    } while(check_stop != 'j');
    
    printf("Avslutar!");
}