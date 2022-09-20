#include <stdio.h>

int main(void)
{
    int distance,speed,time;
    speed = 50;

    printf("Hur lang tid? ");
    scanf("%d", &time);

    distance = speed * time; 

    printf("Med 50 km/h kommer du att fardas %d km.\n",distance);
    printf("Lycka till pa farden\n");
    return 0;
}