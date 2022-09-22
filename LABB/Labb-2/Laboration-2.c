#include <stdio.h>
#include <math.h>
#define SIZE 10

int enterNumber(int measurementArray[], int nrOfMeasurements);
void viewNumber(int measurementArray[], int nrOfMeasurements);
int computeNumber(int measurementArray[], int nrOfMeasurements);
int resetNumber(int measurementArray[], int nrOfMeasurements);
int computeHighest(int measurementArray[], int nrOfMeasurements);
int computeLowest(int measurementArray[], int nrOfMeasurements);
float computeAverage(int measurementArray[], int nrOfMeasurements);
void computeNormal(int measurementArray[], int nrOfMeasurements, float averageNumber, int avgArray[]);


int main()
{
    char menuChoice;
    int measurementArray[SIZE]; 
    int nrOfMeasurements = 0;
    int highestNumber, lowestNumber, normalisedNumber;
    float averageNumber, sum;
    printf("Measurement tool 2.0\n");

    do 
    {
        printf("VECRQ? ");
        scanf(" %c", &menuChoice);

        switch(menuChoice)
        {
            case 'v':
                viewNumber(measurementArray, nrOfMeasurements);
                break;
            case 'e':
                nrOfMeasurements = enterNumber(measurementArray, nrOfMeasurements);
                break;
            case 'c':
                computeNumber(measurementArray, nrOfMeasurements);
                break;
            case 'r':
                nrOfMeasurements = resetNumber(measurementArray, nrOfMeasurements);
                break;
            case 'q':
                printf("Exit measurement tool\n");
                break;
            default:
                printf("Please enter only valid characters (VECRQ): \n");
        }
    } while(menuChoice != 'q');

    return 0;
}

int enterNumber(int measurementArray[],int nrOfMeasurements)
{
    for(int i = nrOfMeasurements; i < SIZE; i++)
    {
        printf("Enter measurement #%d (or q to quit): ", i + 1);

        int readInteger = scanf("%d", &measurementArray[i]);
        if (readInteger)
        {
            nrOfMeasurements++;
        }
        else
        {
            char tmp;
            scanf(" %c",&tmp);
            break; 
        }
    }
    return nrOfMeasurements;
}

void viewNumber(int measurementArray[], int nrOfMeasurements)
{
    printf("[ ");
    for(int i = 0; i < nrOfMeasurements; i++)
    {
        printf("%d ", measurementArray[i]);
    }
    printf("]\n");
}

int resetNumber(int measurementArray[], int nrOfMeasurements)
{
    for(int i = 0; i < nrOfMeasurements; i++)
    {
        measurementArray[i] = 0;
    }
    return 0;
}

int computeNumber(int measurementArray[], int nrOfMeasurements)
{
    int highestNumber, lowestNumber, avgArray[nrOfMeasurements];
    float averageNumber;

    if (nrOfMeasurements == 0)
    {
        printf("No measurements entered\n");
    } 
    else
    {
        highestNumber = computeHighest(measurementArray, nrOfMeasurements);
        printf("Max value: %d\n", highestNumber);
        
        lowestNumber = computeLowest(measurementArray, nrOfMeasurements);
        printf("Min value: %d\n", lowestNumber);
        
        averageNumber = computeAverage(measurementArray, nrOfMeasurements);
        printf("Avr value: %.2f\n", averageNumber);
        
        computeNormal(measurementArray, nrOfMeasurements, averageNumber, avgArray);
        viewNumber(avgArray, nrOfMeasurements);
    } 
}

int computeHighest(int measurementArray[], int nrOfMeasurements)
{
    int highestNumber;
    highestNumber = 0;

    for(int i = 0; i < nrOfMeasurements; i++)
    {
        if (highestNumber < measurementArray[i])
        {
            highestNumber = measurementArray[i];
        }
    }
    return highestNumber;
}

int computeLowest(int measurementArray[], int nrOfMeasurements)
{
    int lowestNumber;
    lowestNumber = measurementArray[0];
    for(int i = 1; i < nrOfMeasurements; i++)
    {
        if (lowestNumber > measurementArray[i])
        {
            lowestNumber = measurementArray[i];
        }
    }
    return lowestNumber;
}

float computeAverage(int measurementArray[], int nrOfMeasurements)
{
    float averageNumber, sum;
    sum = 0;
    for(int i = 0; i < nrOfMeasurements; i++)
    {
        sum = sum + measurementArray[i];
    }
    averageNumber = sum / nrOfMeasurements;
    return averageNumber;
}

void computeNormal(int measurementArray[], int nrOfMeasurements, float averageNumber, int avgArray[])
{
    for(int i = 0; i < nrOfMeasurements; i++)
    {
        avgArray[i] = measurementArray[i] - round(averageNumber);
    }   
}



