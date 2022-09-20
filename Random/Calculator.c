#include <stdio.h>

int main(void)
{
    int nrOfDays, startDay, i; //1-man, 2-tis

    printf("Enter amount of days in a month: ");
    scanf("%d", &nrOfDays);

    do
    {
        printf("Enter number of day (1-monday, 2-tuesday.. etc): ");
        scanf("%d", &startDay);
    } while(startDay<1 || 7<startDay);
    
    printf("  m ti on to  f  l  s\n");
    for(i=1;i < startDay;i++)
    {
        printf("   ");
    }
    for(i=1; i <= nrOfDays; i++)
    {
        printf("%3d", i);
        startDay++;
        if(startDay > 7)
        {
            printf("\n");
            startDay = 1;
        }
    }


    return 0;
}