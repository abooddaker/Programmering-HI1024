#include <stdio.h>

#define MAX_LENGTH 20

int swedishStrings(char string[][MAX_LENGTH+1], int n);
int englishStrings(char string[][MAX_LENGTH+1], int n);
void fillStrings(char string[][MAX_LENGTH+1], char string2[][MAX_LENGTH+1], int n);

int main(void)
{
    int input = 0, position = 0; 
    char swedish[MAX_LENGTH][MAX_LENGTH+1];
    char english[MAX_LENGTH][MAX_LENGTH+1];

    while (input != 4)
    {
        printf("(1) Skriva in (2) Skriva ut (3) Radera (4) Avsluta: ");
        scanf("%d", &input);
        switch(input)
        {
            case 1:
                if (position == 20)
                {
                    printf("Gloslistan ar full");
                    break;
                }
                while(position < 20 && !swedishStrings(swedish, position))
                {
                    englishStrings(english, position);
                    position++;
                }
                break;
            case 2:
                if (position == 0)
                {
                    printf("Gloslistan ar tom\n");
                    break;
                }
                fillStrings(swedish, english, position);
                break;
            case 3:
                position = 0;
                break;
            case 4:
                printf("Avslutar\n");
                break;
        }
    }

    return 0;
}

int swedishStrings(char string[][MAX_LENGTH+1], int n)
{
    printf("Svenska: ");
    scanf("%s", string[n]);
    if (string[n][0] == 'q' && string[n][1] == '\0')
    {
        return 1;
    }
    return 0;
}

int englishStrings(char string[][MAX_LENGTH+1], int n)
{
    printf("Engelska: ");
    scanf("%s", string[n]);
    return 0;
}

void fillStrings(char string[][MAX_LENGTH+1], char string2[][MAX_LENGTH+1], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s", string[i]);
        printf("  -  ");
        printf("%s", string2[i]);
        printf("\n");
    }
}
