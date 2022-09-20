#include <stdio.h>

int main(void)
{
    int number, reversedNumber;

    printf("Enter a number: ");
    scanf("%d", &number);
    printf("The reversal is: ");
    do 
    {
        reversedNumber = number % 10; // 245 % 10 = 5 -> 245 / 10 = 24 -> 24 % 10 = 4 -> 24 / 10 = 2 -> 2 % 10 = 2 etc..
        number /= 10;
        printf("%d", reversedNumber);
    }
    while (number > 0);

    return 0;
}