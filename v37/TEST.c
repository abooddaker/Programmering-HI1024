#include <stdio.h>
#define ROW 5
#define COLUMN 5

int main(void) {

    int i, j, total;
    int a[ROW][COLUMN];

    for (i = 0; i < ROW; i++) 
    {
        printf("Enter row %d: ", i + 1);

        for (j = 0; j < ROW; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Row totals: ");

    for (i = 0; i < ROW; i++) 
    {
        total = 0;
        for (j = 0; j < ROW; j++) 
        {
            total += a[i][j];
        }
        printf("%d ", total);
    }

    printf("\nColumn totals: ");
    for (i = 0; i < ROW; i++) 
    {
        total = 0;
        for (j = 0; j < ROW; j++) 
        {
            total += a[i][j];
        }
        printf("%d ", total);
    }

    printf("\n");

    return 0;
}