#include <stdio.h>

int main ()
{
    int a, b, c, d, min, max;
    

    printf("Enter four integers: ");
    scanf("%d %d %d %d", &a, &b, &c, &d);

    min = a;
    max = a;

    if (b > max) 
    {
        max = b;
    }
    if (b < min)
    {
        min = b;
    }
    if (c > max) 
    {
        max = c;
    }
    if (c < min)
    {
        min = c;
    }
    if (d > max) 
    {
        max = d;
    }
    if (d < min)
    {
        min = d;
    }

    printf("The largest number is: %d\n", max);
    printf("The smallest number is: %d\n", min);
    return 0;
}
