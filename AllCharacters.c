#include <stdio.h>
#include <ctype.h>

int main() {
   printf("| Character | ASCII | Type        |\n");
   printf("| :-------: | ----: | :---------- |\n");
   for (int i = 32; i < 127; i++) {
       printf("|  %3c      | %3d   | ", i, i);
       if (isalpha(i))
           printf("Alphabet    |\n");
       else if (isdigit(i))
           printf("Digit       |\n");
       else if (ispunct(i))
           printf("Punctuation |\n");
       else if (isspace(i))
           printf("Space       |\n");
       else if (iscntrl(i))
           printf("Control     |\n");
   }
   return 0;
}