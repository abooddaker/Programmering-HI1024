#include <stdio.h>

int main(void)
{
    float input, array[100], max = 0;
    int nrOfData = 0;
    float sum = 0, total;
    

    while(1)
    {
        printf("Ange m„tdata: ");
        scanf("%f", &input);
        if (input <= 0)
        {
            break;
        }
        array[nrOfData] = input;
        nrOfData++;
    }

    for(int j = 0; j < nrOfData; j++)
    {
        if(array[j] > max)
        max = array[j];
    }
    for(int i = 0; i < nrOfData; i++)
    {
        sum += array[i];
    }

    if(sum==0)
    {
        printf("Matdata saknas");
    }
    else
    {
    printf("St”rsta matdata: %.3f Summa: %.3f", max, sum);
    }
    

}