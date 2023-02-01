#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20

// Define the Points struct to store x and y coordinates
struct points {
float x;
float y;
};
typedef struct points Points;

void fillAllPoints(Points allPoints[], int nrOfPoints);
void printAllPoints(Points allPoints[], int nrOfPoints);
Points maxPoint(Points allPoints[], int nrOfPoints);
void printLargestPoint(Points p);


int main(void) 
{
    
    srand(time(0));
    Points allPoints[MAX];
    fillAllPoints(allPoints, MAX);
    
    Points largestXPoint = maxPoint(allPoints, MAX);
    printAllPoints(allPoints, MAX);
    printLargestPoint(largestXPoint);
}

void fillAllPoints(Points allPoints[], int nrOfPoints)
{
    for(int i = 0; i < nrOfPoints; i++)
    {
        allPoints[i].x = (float) rand() /  RAND_MAX * 1;
        allPoints[i].y = (float) rand() /  RAND_MAX * 1;
    }
}

void printAllPoints(Points allPoints[], int nrOfPoints)
{
    for(int i = 0; i < nrOfPoints; i++)
    {
        printf("(%.2f,%.2f) ", allPoints[i].x, allPoints[i].y);
    }
}

Points maxPoint(Points allPoints[], int nrOfPoints)
{
    Points largestXPoint = allPoints[0];

    for(int i = 1; i < nrOfPoints; i++)
    {
        if(allPoints[i].x > largestXPoint.x)
        {
            largestXPoint = allPoints[i];
        }
    }
    return largestXPoint;
}

void printLargestPoint(Points p)
{
    printf("\nLargest point: (%.2f, %.2f)", p.x, p.y);
}