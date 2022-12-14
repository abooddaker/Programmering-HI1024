#include <stdio.h>
#define MAXCHAR 10

struct city {
    int year; 
    float population;
    char Name[MAXCHAR];
}; typedef struct city Cities;


void printCity(Cities c);
Cities swapPopulation(Cities *city1, Cities *city2);

int main(void)
{
    Cities city1 = {1920, 1.501, "Stockholm"};
    Cities city2 = {1820, 0.435, "Goteborg"};

    printCity(city1);
    printCity(city2);
    swapPopulation(&city1, &city2);
    printf("\n");
    printCity(city1);
    printCity(city2);

    return 0;
}

void printCity(Cities c)
{
    printf("Year founded: %d, population %.2f, name: %s \n", c.year, c.population, c.Name);
}

Cities swapPopulation(Cities *city1, Cities *city2)
{
    float temp = city1 -> population;
    city1 -> population = city2 -> population;
    city2 -> population = temp;    
}

