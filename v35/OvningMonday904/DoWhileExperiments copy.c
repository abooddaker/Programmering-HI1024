#include <stdio.h>

int main(void)
{
    int n, k, sum = 0;

    for (k=1;k<10;k++)
    {
        sum = sum + k; //
        printf("%dK,\n ", k);
        printf("%dSUM,\n ", sum);
    }
    
        return 0;

}