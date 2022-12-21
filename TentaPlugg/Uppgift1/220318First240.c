#include <stdio.h>

int main(void)
{
    int nrOfOperations = 0, points = 1;
    char input;
    printf("Kom till 40 s† fort som m”jligt.\n");
    while(points < 40)
    {
        printf("Du har nu %d. Vill du a) *3 b) +4 c) -1: ", points);
        scanf(" %c", &input);
        if(input == 'a')
        {
            points *= 3;
        }
        if(input == 'b')
        {
            points += 4;
        }
        if(input == 'c')
        {
            points -= 1;
        }
        nrOfOperations++;
    }
    printf("Grattis du nadde %d. Det tog %d operationer", points, nrOfOperations);

}