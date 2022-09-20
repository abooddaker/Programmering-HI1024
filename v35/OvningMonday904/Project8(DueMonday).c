#include <stdio.h>

int main(void)
{
    int column, row, numberOfRows;

    printf("Enter number of rows/colums: ");
    scanf("%d", &numberOfRows);

    for (row = 1; row <= numberOfRows; row++) 
    {
        for (column = 1; column <= numberOfRows; column++)
        {
            if ((row == column) || (row + column) == (numberOfRows + 1))
                 
            {
                printf(" * ");
            }
            else
            {
                printf(" + ");
            }
        }
        printf("\n");
    }
    return 0;

}