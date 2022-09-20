#include <stdio.h>

int main()

{
    int time, hour, minute, flight1, flight2, flight3, flight4, flight5, flight6, flight7, flight8;
    
    flight1 = 480;
    flight2 = 583;
    flight3 = 679;
    flight4 = 767;
    flight5 = 840;
    flight6 = 945;
    flight7 = 1140; 
    flight8 = 1305;

    printf("Enter any 24-hour time: ");
    scanf("%d :%d", &hour, &minute);

    time = hour * 60 + minute;
    {
    if (time <= flight1 + (flight2 - flight1) / 2)
        printf("Closest departure time is 8:00 a.m., arriving at 10:16 a.m.");
    }


}