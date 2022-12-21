#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define NROFCHAR 4
#define MAXSTRING 10

void getCode(char code[]);
void getGuess(char guess[]);
int okGuess(char guess[]);
int nrOfCorrect(char code[],char guess[]);

int main(){
    srand(time(NULL));
    char code[NROFCHAR+1],guess[MAXSTRING]="";
    getCode(code);
    //printf("hemlig kod: %s\n",code);
    while(strcmp(code,guess)!=0){
        getGuess(guess);
        if(strcmp(code,guess)!=0){
            printf("%d korrekta\n",nrOfCorrect(code,guess));
        }
    }
    printf("Korrekt kod\n");
    return 0;
}

int nrOfCorrect(char code[],char guess[]){
    int nrCorrect=0;
    for(int i=0;i<NROFCHAR;i++)
        if(code[i]==guess[i]) nrCorrect++;
    return nrCorrect;
}

void getGuess(char guess[]){
    do{
        printf("Gissa en kod (fyra bokstaver a-g): ");
        scanf("%s",guess);
    }while(!okGuess(guess));
}

int okGuess(char guess[]){
    if(strlen(guess)!=NROFCHAR){
        printf("Felaktig inmatning\n");
        return 0;
    }
    for(int i=0;i<NROFCHAR;i++)
        if(guess[i]<'a'||'g'<guess[i]){  
            printf("Felaktig inmatning\n");
            return 0;
        }
    return 1;
}

void getCode(char code[]){
    int taken['g'-'a'+1]={0};
    char letter;
    for(int i=0;i<NROFCHAR;i++){
        do{
            letter='a'+rand()%('g'-'a'+1);
        }while(taken[letter-'a']);
        taken[letter-'a']=1;
        code[i] = letter;
    }
    code[NROFCHAR]=0;
}