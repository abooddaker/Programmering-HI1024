#include <stdio.h>

int main(void)
{
    int i,j; 
    
    for (i=1;i<=10;i=i+1)
    {
            for (j=1;j<=3;j=j+1)
            {
                printf("(%d,%d)", i, j);
            }
            printf("\n");
    }

}