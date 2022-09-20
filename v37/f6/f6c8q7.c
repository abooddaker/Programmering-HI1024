#include <stdio.h>
#define ROW 5
#define COLUMN 5

int main(void) 
{

    int i, j, total;
    int n[ROW][COLUMN];

    for (i = 0; i < ROW; i++) 
    {
        printf("Enter row %d:    ", (i + 1));

        for (j = 0; j < ROW; j++) 
        {
            scanf("%d", &n[i][j]);
        }
    }

    printf("Total rows:     ");

    for (i = 0; i < ROW; i++) 
    {
        total = 0;
        for (j = 0; j < ROW; j++) 
        {
            total += n[i][j];
        }
        printf("%d ", total);
    }

    printf("\nTotal columns:  ");
    
    for (i = 0; i < ROW; i++) 
    {
        total = 0;
        for (j = 0; j < ROW; j++) 
        {
            total += n[j][i];
        }
        printf("%d ", total);
    }

    printf("\n");

    return 0;
}