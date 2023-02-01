#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define CODE_LENGTH 4

void generate_code(char code[CODE_LENGTH]) {
  srand(time(NULL));

  for (int i = 0; i < CODE_LENGTH; i++) 
  {
    int letter = rand() % 7;

    switch (letter) 
    {
        case 0:
        code[i] = 'a';
        break;
        case 1:
        code[i] = 'b';
        break;
        case 2:
        code[i] = 'c';
        break;
        case 3:
        code[i] = 'd';
        break;
        case 4:
        code[i] = 'e';
        break;
        case 5:
        code[i] = 'f';
        break;
        case 6:
        code[i] = 'g';
        break;
    }
  }
  
}

// Function to check if a guess is valid
int check_guess(char guess[CODE_LENGTH]) {
  // Check if the guess has the correct number of letters
  if (strlen(guess) != CODE_LENGTH) {
    return 0;
  }

  // Check if the guess contains only valid letters
  for (int i = 0; i < CODE_LENGTH; i++) {
    if (guess[i] < 'a' || guess[i] > 'g') {
      return 0;
    }
  }

  return 1;
}

int main() 
{
  char code[CODE_LENGTH];
  char guess[CODE_LENGTH];

  // Generate the code
  generate_code(code);

  // Prompt the user to enter their guess
  printf("Enter your guess (4 letters): ");
  scanf("%s", guess);

  // Keep prompting the user until they enter a valid guess
  while (!check_guess(guess)) {
    printf("Invalid guess. Try again (4 letters): ");
    scanf("%s", guess);
  }

  // Check how many letters in the guess match the code
  int correct = 0;
  for (int i = 0; i < CODE_LENGTH; i++) {
    if (guess[i] == code[i]) {
      correct++;
    }
  }

  // Keep prompting the user until they guess the correct code
  while (correct != CODE_LENGTH) {
    printf("%d letters correct. Try again: ", correct);
    scanf("%s", guess);

    // Check if the guess is valid
    while (!check_guess(guess)) {
      printf("Invalid guess. Try again (4 letters): ");
      scanf("%s", guess);
    }
  }
    // Check how many letters in the guess match the code
    correct = 0;
    //for (int i = 0
}