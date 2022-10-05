#include <stdio.h>
#include <string.h>
#define WORDLENGTH 30

struct car{
    char model[WORDLENGTH];
    int year;
    int milage;
};

int main(){
    struct car c1;
    strcpy(c1.model,"Volvo");
    c1.year = 1971;
    c1.milage = 21000;
    printf("Bil: %s, Arsmodell: %d, Mil: %d", c1.model, c1.year, c1.milage);
}