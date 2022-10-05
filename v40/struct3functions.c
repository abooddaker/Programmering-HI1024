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

/*int main(){
    Car c1;
    strcpy(c1.model,"Volvo");
    c1.year = 1971;
    c1.milage = 21000;
    printf("Bil: %s, Arsmodell: %d, Mil: %d", c1.model, c1.year, c1.milage);
} */

int main()
{
    Car c1 = {"Volvo", 2013, 2100}, c2 = {"Saab", 1992, 23000}, c3;
    c3 = c2;
    c3.milage = c3.milage + 1000;
    showCar(c1);
    showCar(c2);    
    showCar(c3);    

    return 0;
}

void showCar(Car c){
    printf("Bil: %s, Arsmodell: %d, Mil: %d", c.model, c.year, c.milage);
    printf("\n");
}