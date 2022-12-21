#include <stdio.h>
#include <string.h>

/*
int main()
{
    char fullName[20];
    gets(fullName);

    printf("Your name is: ");
    puts(fullName); // or printf

    return 0;
}
*/

int main() {
    char s1[100];
    char s2[10];
    char s3[] = {"What the fuck is going on"};
    printf("Enter a string: ");

    scanf("%s", s1);
    scanf("%s", s2);

    //scanf("%[^\n]", s1);

   // scanf("%[^\n]", s2);
    printf("You entered: %s and %s\n", s1, s2);
    strcat(s2,s1);
    //printf("%d", strlen(s1));
    printf("%s bro....\n", s2);

    int count = 0;

    for(int i = 0; s3[i] != '\0'; i++)
    {
        if(s3[i] == ' ')
        {
            count++;
        }
    }
    printf("%s\n", s3);
    printf("Amount of spaces in the 3rd string:  %d", count);
    return 0;
}
