#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5

struct points{
    float x,y;
}; typedef struct points Points;

void fill(Points points[], int nrOfPoints);
Points findLargest(Points points[], int nrOfPoints);
void printPoints(Points points[], int nrOfPoints);
void printPoint(Points p);

int main(void)
{
    Points points[MAX];
    fill(points, MAX);
    printPoints(points, MAX);
    printPoint(findLargest(points, MAX));

    return 0;

}

void fill(Points points[], int nrOfPoints)
{
    srand(time(NULL));

    for(int i = 0; i < nrOfPoints; i++)
    {
        points[i].x = (float) rand() / RAND_MAX * 0.99;
        points[i].y = (float) rand() / RAND_MAX * 0.99;
    }
}

Points findLargest(Points points[], int nrOfPoints)
{
    Points findLargest = points[0];

    for(int i = 0; i < nrOfPoints; i++)
    {
        if(points[i].x > findLargest.x)
        {
            findLargest = points[i];
        }
    }
    return findLargest;
}

void printPoints(Points points[], int nrOfPoints)
{   
    for(int i = 0; i < nrOfPoints; i++)
    {
        printf("(%.2f,%.2f),", points[i].x, points[i].y);
    }
}

void printPoint(Points p)
{
    printf("\n(%.2f,%.2f)", p.x, p.y);
}