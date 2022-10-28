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


void increaseMilage(Car *pCar, int mile){
    
    (*pCar).milage = (*pCar).milage + mile;
}

void printCar(Car c1)
{
printf("Bil: %s, Arsmodell: %d, Mil: %d\n",c1.model,c1.year,c1.milage);
}

int main()
{
    Car c1 = {"Volvo", 2013, 20000}, c3;
    Car c2 = {"BMW", 2022, 10000};
    c3 = c2;

    c3.milage = c3.milage - 9500;
    c2.year = c2.year - 22;

    increaseMilage(&c1, 20);
    printCar(c1);
    printCar(c2);
    printCar(c3);
    /* 
    printf("Bil: %s, Ar: %d, Milage: %d\n", c1.model, c1.year, c1.milage);
    printf("Bil: %s, Ar: %d, Milage: %d\n", c2.model, c2.year, c2.milage);
    printf("Bil: %s, Ar: %d, Milage: %d\n", c3.model, c3.year, c3.milage);
    */
    return 0;
}