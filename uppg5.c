#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    
    char test[] = {'a','b','c','d','e','f','g'};

    srand(time(NULL));

    test[rand() % 7]; 

    printf("%c", test);
}