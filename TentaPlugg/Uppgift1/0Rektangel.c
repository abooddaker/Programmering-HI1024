#include <stdio.h>

int main(void) 
{
    int row, column; 

    printf("Ange hojd: ");
    scanf("%d", &row);
    printf("Ange bredd: ");
    scanf("%d", &column);

    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < column; j++) 
        {
            if (i == 0 || i == row - 1 || j == 0 || j == column - 1) 
            {
                printf("*");
            } 
            else 
            {
                printf(" ");
            }
        }
        printf("\n");
    }

  return 0;
}