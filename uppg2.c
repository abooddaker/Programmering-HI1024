//observera att denna går utmärkt att lösa utan pekare om man så vill
#include <stdio.h>
#include <string.h>
#define SIZE 10
#define WORDSIZE 31

void add(char registry[][WORDSIZE],int *pNrOfWords);
void print(char registry[][WORDSIZE],int nrOfWords);
int uniqueWord(char registry[][WORDSIZE],int nrOfWords,char newWord[]);
void delete(char registry[][WORDSIZE],int *pNrOfWords);
int getIndex(char registry[][WORDSIZE],int nrOfWords,char word[]);
void printRobbers(char registry[][WORDSIZE],int nrOfWords);
void printRobber(char word[]);
int isConsonant(char c);

int main(){
    char choice = 'a';
    char registry[SIZE][WORDSIZE];
    int nrOfWords = 0;

    while(choice!='d'){
        printf("a) lagga till, b) skriva ut, c) ta bort, d) avsluta, e) rovarsprak: ");
        scanf("%c%*c",&choice);
        switch (choice)
        {
            case 'a': add(registry,&nrOfWords);
            break;
            case 'b': print(registry,nrOfWords);
            break;
            case 'c': delete(registry,&nrOfWords);
            break;
            case 'd':
            break;
            case 'e': printRobbers(registry,nrOfWords);
            break;
            default:printf("Felaktigt val\n");
            break;
        }
    }
    printf("Avslutar\n");

    return 0;
}

void printRobbers(char registry[][WORDSIZE],int nrOfWords){
    for(int i=0;i<nrOfWords;i++){
        printRobber(registry[i]);
        printf(", ");
    }
    printf("\n");
}

void printRobber(char word[]){
    for(int i=0;word[i]!=0;i++){
        if(isConsonant(word[i])){
            printf("%co%c",word[i],word[i]);
        }else{
            printf("%c",word[i]);
        }
    }
}

int isConsonant(char c){
    char consonants[] = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','z'};
    for(int i=0;i<sizeof(consonants)/sizeof(char);i++){
        if(c == consonants[i]) return 1;
    }
    return 0;
}

void delete(char registry[][WORDSIZE],int *pNrOfWords){
    char word[WORDSIZE];
    int index;
    while(1){
        printf("Ange ord att radera (q for avslut): ");
        scanf("%s%*c",word);
        if(strcmp(word,"q")==0) break;
        index = getIndex(registry,*pNrOfWords,word);
        if(index == -1){
            printf("Ordet saknas\n");
        }else{
            for(int i=index;i<*pNrOfWords-1;i++)
                strcpy(registry[i],registry[i+1]);
            (*pNrOfWords)--;
        }
    }
}

int getIndex(char registry[][WORDSIZE],int nrOfWords,char word[]){
    for(int i=0;i<nrOfWords;i++){
        if(strcmp(registry[i],word)==0) return i;
    }
    return -1;
}

void print(char registry[][WORDSIZE],int nrOfWords){
    for(int i=0;i<nrOfWords;i++){
        printf("%s, ",registry[i]);
    }
    printf("\n");
}

void add(char registry[][WORDSIZE],int *pNrOfWords){
    while(*pNrOfWords<SIZE){
        printf("Ange ord (q for avslut): ");
        scanf("%s%*c",registry[*pNrOfWords]);
        if(strcmp(registry[*pNrOfWords],"q")==0) break;
        if(getIndex(registry,*pNrOfWords,registry[*pNrOfWords])==-1){
            (*pNrOfWords)++;
        }else{
            printf("Ordet finns redan.\n");
        }
    }
}