#include <stdio.h>

int main(void)
{
    int base = 0, column, row;
    while(base < 1 || base > 10)
    {
        printf("Ange bas (1-10): ");
        scanf("%d", &base);
        if(base < 1 || base > 10)
        {
            printf("Felaktig val\n");
        }
    }

    for(row = 0; row < base; row++)
    {
        for(column = 0; column < base - row; column++)
        {
            printf("*");
        }
        printf("\n");
    }
}