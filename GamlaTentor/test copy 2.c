#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int freq[13]={0},diceResult,k;
    srand(time(0));
    for(k=1;k<=10000;k++)
    {
        diceResult = (rand()% 6 + 1) + (rand()% 6 + 1);
        freq[diceResult]++;
    }

    for(k=2;k<=12;k++)
    {
        printf("Antal %2d: %d. Andel: %.2f%%\n",k,freq[k],100*freq[k]/10000.);
    }
    return 0;
}