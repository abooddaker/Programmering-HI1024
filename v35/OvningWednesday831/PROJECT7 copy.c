#include <stdio.h>

int main(void)
{
    int amount, bills, bill1, bill2, bill3, bill4;

    printf("Enter a dollar amount:");
    scanf("%d", &amount);

    printf("Enter bill 1:");
    scanf("%d", &bill1);

    printf("Enter bill 2:");
    scanf("%d", &bill2);

    printf("Enter bill 3:");
    scanf("%d", &bill3);

    printf("Enter bill 4:");
    scanf("%d", &bill4);



    bills = amount / bill1;
    printf("%d kr bills: %d\n",bill1, bills);

    amount = amount - (bills * bill1);
    
    bills = amount / bill2;
    printf("%d kr bills: %d\n",bill2, bills);

    amount = amount - (bills * bill2);

    bills = amount / bill3;
    printf("%d kr bills: %d\n",bill3, bills);

    amount = amount - (bills * bill3);
    bills = amount / bill4;
    
    printf("%d kr bills: %d\n",bill4, bills);

    return 0;
}