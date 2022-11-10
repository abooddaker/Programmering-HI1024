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

void swapPopulation(float *c1, float *c2)
{
    float temp = *c1;
    *c1 = *c2;
    *c2 = temp;
}

int main()
{
    Cities c1 = {2.5, 1550, "Stockholm"};
    Cities c2 = {1.5, 1650, "Goteborg"};

    printCity(c1);
    printCity(c2);

    swapPopulation(&c1.population, &c2.population);

    printf(">>Swapping \n");

    printCity(c1);
    printCity(c2);
    
}