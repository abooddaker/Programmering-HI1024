#include <stdio.h>

int main(void)

{
    int number;

    printf("Enter any three digit number: ");
    scanf("%d", &number);
    printf("The reversed number is: %d%d%d", number % 10, (number / 10) % 10, number / 100);
}