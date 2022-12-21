#include <stdio.h>
#define CHARMAX 20 

struct city{
    int year;
    float population;
    char cityName[CHARMAX];
}; typedef struct city Cities;

void printCity(Cities c);
Cities swapName(Cities *city1, Cities *city2);
Cities swapPopulation(Cities *city1, Cities *city2);
Cities swapYear(Cities *city1, Cities *city2);


int main()
{
    Cities city1 = {1252, 1.515, "Stockholm"};
    Cities city2 = {1621, 0.608, "Goteborg"};

    printCity(city1);
    printCity(city2);

    swapName(&city1, &city2);
    swapPopulation(&city1, &city2);
    swapYear(&city1, &city2);
    
    printCity(city1);
    printCity(city2);

}

void printCity(Cities c)
{
    printf("%s, folkm„ngd: %.2f miljoner, grundat †r: %d\n", c.cityName, c.population, c.year);
}

Cities swapName(Cities *city1, Cities *city2)
{
    char temp[CHARMAX] = city1 -> cityName[CHARMAX];
    city1 -> cityName[CHARMAX] = city2 -> cityName[CHARMAX];
    city2 -> cityName[CHARMAX] = temp[CHARMAX]; 
}

Cities swapPopulation(Cities *city1, Cities *city2)
{
    float temp = city1 -> population;
    city1 -> population = city2 -> population;
    city2 -> population = temp;
}

Cities swapYear(Cities *city1, Cities *city2)
{
    int temp = city1 -> year;
    city1 -> year = city2 -> year;
    city2 -> year = temp;
}