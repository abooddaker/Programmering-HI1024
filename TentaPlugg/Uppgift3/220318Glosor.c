#include <stdio.h>
#include <string.h>
#define MAX 20

struct vocab {
    char english[MAX], swedish[MAX];
}; typedef struct vocab Vocab;

void printPair(Vocab v);
void changeSwedish(Vocab *v, char newWord[]);

int main(){
    Vocab wordPair1 = {"cat", "katt"};
    printPair(wordPair1);
    changeSwedish(&wordPair1, "kattdjur");
    printPair(wordPair1);
    return 0;
}

void printPair(Vocab v){
    printf("%s - %s\n", v.english, v.swedish);
}

void changeSwedish(Vocab *v, char newWord[]){
    strcpy(v -> swedish, newWord);
}