#include <stdio.h>

int main(void)
{
    float Height, Velocity;
    int Time, Throttle;

    printf("\n");
    printf("Lunar decent challenge!\n");
    printf("You will pilot a lunar decent the last 250m\n");
    printf("Each turn will represent a 1-second decent time\n");
    printf("Set the throttle for each turn (0-100)\n");
    printf("Time Height Velocity Throttle?: ");
    printf("\n");
    
    Height = 250;
    Velocity = -25;
    Time = 0;

    while(Height > 0)
    {
        printf("%4d %6.1f %6.1f   ", Time, Height, Velocity);
        scanf("%d", &Throttle);
        
        if(Throttle<0 || 100<Throttle)
        {
            printf("The value entered should be between 0 and 100, try again: \n");
        }
        else
        {
            Time++;
            Height = Height + Velocity + ((0.1 * Throttle - 1.5)/2);
            Velocity = Velocity + (0.1 * Throttle - 1.5);
        }
    }
    
    if(Velocity < -2)
    {
        printf("MISSION FAILED! Crash landing at %.1f m/s", Velocity);
    }
    else
    {
        printf("SUCCESS! You landed your ship at a speed of %.1f m/s", Velocity);
    }

    return 0;
}