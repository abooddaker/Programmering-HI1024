#include <stdio.h>
#define ROW 5
#define COLUMN 5

int main()
{
    /*
    int grade1 = 10, grade2 = 5;

    printf("ADDRESS 1: %p\n", &grade1);
    printf("ADDRESS 2: %p\n", &grade2);

    printf("VALUE 1: %d\n", grade1);
    printf("VALUE 2: %d\n", grade2);
    */
    int a[4];

    for(int i = 0; i < 4; i++)
    {
        a[i] = i + 1;
        printf("%d", a[i]);
    }

    
}
