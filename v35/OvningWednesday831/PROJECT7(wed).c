#include <stdio.h>

int main(void)
{
    int amount, bills;

    printf("Enter a dollar amount:");
    scanf("%d", &amount);


    bills = amount / 20;
    printf("20$ bills: %d\n", bills);

    amount = amount - (bills * 20);
    
    bills = amount / 10;
    printf("10$ bills: %d\n", bills);

    amount = amount - (bills * 10);

    bills = amount / 5;
    printf(" 5$ bills: %d\n", bills);

    amount = amount - (bills * 5);
    bills = amount / 1;

    printf(" 1$ bills: %d\n", bills);

    return 0;
}