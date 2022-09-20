#include <stdio.h>
#define LENGTH 10

int main(void)
{
    int digit_seen[LENGTH] = {0};
    int digit;
    long n;
//    [8,2,4,0,1,2,0,0,0,0,0]
    printf("Enter a number: ");
    scanf("%ld", &n); //155
    

    while (n > 0) {
        digit = n % 10; //5

        digit_seen[digit]++; 

        n /= 10; //15 


    } 
    printf("The repeated numbers are: ");

    for(int i=0; i < LENGTH;i++)
    { 
   
        if (digit_seen[i] > 1)
    {
        printf("%d ", i);
    }
    }

    return 0;
}

/*
    if (n > 0)
        printf("Repeated digit\n");
    else
        printf("No repeated digit\n");
    
    return 0;
}*/