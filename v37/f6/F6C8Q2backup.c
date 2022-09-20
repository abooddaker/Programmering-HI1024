#include <stdio.h>
#define LENGTH 10

int main(void)
{
    int digit_seen[LENGTH] = {0};
    int digit;
    long n;
    
    printf("Enter a number: ");
    scanf("%ld", &n); //155
   
    while (n > 0)
    {
        while (n > 0) 
        {
            digit = n % 10; //5
            digit_seen[digit]++; 
            n /= 10; //15 
        } 
        
        printf("\n\nDigit:         0  1  2  3  4  5  6  7  8  9\n");
        printf("Occurencies:   ");
        
        for (int i=0; i < LENGTH;i++)
        {
            printf("%d  ", digit_seen[i]);
            digit_seen[i] = 0;
        }
        
        printf("ENter your number");
        scanf("%ld", &n);
    }
    return 0;
}
