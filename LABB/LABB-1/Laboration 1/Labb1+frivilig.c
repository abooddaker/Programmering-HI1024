#include <stdio.h>

int main(void)
{
    float Height, Velocity;
    int Time, Throttle, Fuel;

    printf("\n");
    printf("Lunar decent challenge!\n");
    printf("You will pilot a lunar decent the last 250m\n");
    printf("Each turn will represent a 1-second decent time\n");
    printf("Set the throttle for each turn (0-100)\n");
    printf("Time Fuel Height Velocity Throttle?: ");
    printf("\n");
    
    Height = 250;
    Velocity = -25;
    Time = 0;
    Fuel = 500;

    while(Height > 0 && Fuel > 0)
   
    {
    printf("%4d  %4d  %6.1f %6.1f     ", Time, Fuel, Height, Velocity);
    scanf(" %d", &Throttle);
    
    if(Throttle<0 || 100<Throttle)
    {
        printf("The value entered should be between 0 and 100, try again: \n");
    }
    else
    {
    Time++;
    Height = Height + Velocity + ((0.1 * Throttle - 1.5)/2);
    Velocity = Velocity + (0.1 * Throttle - 1.5);
    Fuel = Fuel - Throttle;
    }
    }

    
    if (Velocity < -2)
    {
        printf("MISSION FAILED! Crash landing at %.1f m/s", Velocity);
    }
    else if (Fuel >0)
    {
        printf("Oh no you ran out of fuel");
        
    }
    else
    {
        printf("SUCCESS! You have landed with a speed of %.1f m/s and you still have %dkg fuel remaining.", Velocity, Fuel);
    }
    return 0;
}
