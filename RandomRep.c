#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
int main()
{
    char ch; 
    scanf("%c", &ch);

    if('a' <= ch && ch <= 'z')
    {
        ch = ch - 'a' + 'A';
    }
    printf("%c", ch);
} */

int main()
{
    int v[12];
    for(int i = 0; i < 12; i++)
    {
        v[i] = i + 1; 
    }
    for(int i = 0; i < 12; i++)
    {
        int j = rand() % 12;
        swap (v,i,j); 
    }
}

void swap(int a[], int i, int j)
{
    int tmp = a[i]
    a[i] = a[j];
    a[j] = tmp;
}