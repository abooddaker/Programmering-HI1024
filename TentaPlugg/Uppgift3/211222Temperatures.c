#include <stdio.h>
#include <string.h>
#define CHARMAX 11
struct temperature
{
    char date[11];
    float temps[10];
    int nrOfTemp;
}; typedef struct temperature TempData;

void printTemp(TempData t);
void concatenate(TempData *t1, TempData *t2);
int main(void)
{
    TempData temperatures1 = {"2021-06-27", {18.7, 19.2, 18.3}, 3};
    TempData temperatures2 = {"2021-06-27", {22.1, 23.4}, 2};

    printTemp(temperatures1);
    concatenate(&temperatures1,&temperatures2);
    printTemp(temperatures1);

    return 0;
}

void printTemp(TempData t)
{
    printf("%s ", t.date);
    for(int i = 0; i < t.nrOfTemp; i++)
    {
        printf("%.1f, ", t.temps[i]);
    }
    printf("\n");
}

void concatenate(TempData *t1, TempData *t2)
{
    if(strcmp(t1 -> date, t2 -> date) != 0)
    {
        return;
    }
    else 
    {      
        for(int i = 0; i < t2 -> nrOfTemp; i++)
        {
            if (t1 -> nrOfTemp == 10) break;
            t1 -> temps[t1 -> nrOfTemp] = t2 -> temps[i];
            t1->nrOfTemp++;
        } 
    }
}

