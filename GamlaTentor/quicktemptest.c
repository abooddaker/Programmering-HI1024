#include <stdio.h>
#define MAXNRTEMPS 10

struct temp
{
    char date[20];
    float data[MAXNRTEMPS];
    int nrOfData;
};
typedef struct temp Temp;

void printTemp(Temp c);

int main()
{
    Temp temperatures1 = {"2021-06-27",{18.7, 19.2, 18.3},3};
    printTemp(temperatures1);

}

void printTemp(Temp c)
{
    printf("%s ", c.date);

    for ( int i = 0; i < c.nrOfData;i++)
    {
        printf("%.1f, ", c.data[i]);
    }
}