#include <stdio.h>

int main()
{
    printf("Summer heltal\n");
    printf("Skriv in heltal, avsluta med 0\n");

    int n=1, sum=0;

    while (n != 0)
    {
        scanf("%d", &n);
        sum = sum + n;
    }
        printf("Summa: %d \n", sum);
    return 0;
}
