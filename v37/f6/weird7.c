#include <stdio.h>
#define ROW 5
#define COLUMN 5

int main(void)
{

    int a[ROW][COLUMN];
    int total;

    for (int j = 0; j < ROW; j++)
    {        
        printf("Enter row %d : ", (j + 1));

        for (int i = 0; i < ROW; i++)
            {
                scanf("%d", &a[i][j]);
            }
    
    }
    
    printf("Total rows: ");

    for (int i = 0; i < ROW; i++) 
    {
        total = 0;
        for (int j = 0; j < ROW; j++) 
        {
            total += a[i][j];
        }
        printf("%d ", total);
    }

    printf("\nColumn totals: ");

    for (int i = 0; i < ROW; i++) 
    {
        total = 0;
        for (int j = 0; j < ROW; j++) 
        {
            total += a[i][j];
        }
        printf("%d ", total);
    }

    return 0;
}
