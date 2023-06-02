#include <stdio.h>

#define MAX_LENGTH 20

int write_swe(char str[][MAX_LENGTH+1], int n);
int write_eng(char str[][MAX_LENGTH+1], int n);
void print_words(char str[][MAX_LENGTH+1], char str2[][MAX_LENGTH+1], int n);

int main(void)
{
    int input = 0, position = 0; 
    char swe_words[MAX_LENGTH][MAX_LENGTH+1], eng_words[MAX_LENGTH][MAX_LENGTH+1];

    while (input != 4)
    {
        printf("(1) Skriva in (2) Skriva ut (3) Radera (4) Avsluta: ");
        scanf("%d", &input);
        switch(input)
        {
            case 1:
                if (position == 20)
                {
                    printf("Gloslistan „r full");
                    break;
                }
                while(position < 20 && !write_swe(swe_words, position))
                {
                    write_eng(eng_words, position);
                    position++;
                }
                break;
            case 2:
                if (position == 0)
                {
                    printf("Gloslistan „r tom\n");
                    break;
                }
                print_words(swe_words, eng_words, position);
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

int write_swe(char str[][MAX_LENGTH+1], int n)
{
    printf("Svenska: ");
    scanf("%s", str[n]);
    if (str[n][0] == 'q' && str[n][1] == '\0')
    {
        return 1;
    }
    return 0;
}

int write_eng(char str[][MAX_LENGTH+1], int n)
{
    printf("Engelska: ");
    printf("Svenska: ");
    scanf("%s", str[n]);
    return 0;
}

void print_words(char str[][MAX_LENGTH+1], char str2[][MAX_LENGTH+1], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s", str[i]);
        printf("  -  ");
        printf("%s", str2[i]);
        printf("\n");
    }
}