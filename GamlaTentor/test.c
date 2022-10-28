#include <stdio.h>


int swap(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;

    return a;
}

void main()
{
    int a = 5, b = 7;
    printf("First number before swap = %d\n", a);
    printf("Second number before swap = %d\n", b);
    swap(a,b);
    printf("First number after swap = %d \n", a);
    printf("Second number after swap = %d \n", b);
}