#include <stdio.h>
#define WORDLENGTH 20

struct city
{
    float population;
    int year;
    char cityName[WORDLENGTH];
};
typedef struct city Cities;

void printCity(Cities c)
{
    printf("Population: %.2f, Year founded: %d, City name: %s\n", c.population, c.year, c.cityName);

}

Cities swapPopulation(Cities *pC1, Cities *pC2)
{
    float temp = pC1 -> population;
    pC1 -> population = pC2 -> population;
    pC2 -> population = temp;
}

int main()
{
    Cities c1 = {2.5, 1550, "Stockholm"};
    Cities c2 = {1.5, 1650, "Goteborg"};

    printCity(c1);
    printCity(c2);

    swapPopulation(&c1, &c2);
    printf("\n");
    printf(">>Swapping population between Stockholm and Goteborg\n");
    printf("\n");

    printCity(c1);
    printCity(c2);
    
}