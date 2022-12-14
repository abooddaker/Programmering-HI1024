#include <stdio.h>
#include <string.h>
#define WORDLENGTH 30


struct car
{
    char model[WORDLENGTH];
    int year;
    int milage;
};
typedef struct car Car; 

Car createCar(char model[],int year, int milage)
{
    Car c;
    strcpy(c.model,model);
    c.year=year;
    c.milage=milage;
    return c; //Žntligen kan vi returnera flera v„rden!
}

Car printCar(Car c)
{
    printf("Bil: %s, Year: %d, Milage: %d\n", c.model, c.year, c.milage);
}

int main()
{
    Car c1, c2;
    c1 = createCar("Volvo",2013,2100);
    c2 = createCar("Saab",1992,23000);
    printCar(c1);
    printCar(c2);
    return 0;
}