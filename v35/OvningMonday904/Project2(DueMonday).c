#include <stdio.h>

int main(void)
{
    int a, b, number, divisor, rest;
    
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    if (a>b)
    {
        number = a;
        divisor = b;
    } 
    else 
    {
        number = b;
        divisor = a;
    }
    
while(divisor != 0)
{
    rest = number % divisor;
    number = divisor; 
    divisor = rest;
}
printf("The GCN is: %d", number);

return 0;

}
