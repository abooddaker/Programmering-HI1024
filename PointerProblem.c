#include <stdio.h>
#include <string.h>
#define MAX 3
#define WORDSIZE 31


int EnterWords(char words[][WORDSIZE],int nrOfWords);
void view(char words[][WORDSIZE],int nrOfWords);

int main(){
    char menu; 
    char words[MAX][WORDSIZE];
    int nrOfWords = 0;
    do{
        printf("a) lagga till, b) skriva ut, c) ta bort, d) avsluta: ");
        scanf(" %c", &menu);
        switch(menu){
            case 'a':
                nrOfWords = EnterWords(words,nrOfWords);
                break;
            case 'b':
                view(words,nrOfWords);
                break;
            case 'c':
               nrOfWords = 0;
                break;
            case 'd':
             printf("avsluta");
                break;
            default:printf("Felaktigt val\n");
                break;
        }
    }
    while(menu != 'd');
    return 0;
}

int EnterWords(char words[][WORDSIZE],int nrOfWords){
    char check[WORDSIZE];
    for(int i = nrOfWords; i < MAX; i++)
    {
        printf("ange ord (q for avslut):");
        scanf("%s", check);
        if(strcmp(check,"q")==0)
        { 
        break;
        } 
        else
        {
            strcpy(words[i], check);
            nrOfWords++;
        }
    }
    return nrOfWords; 
}

void view(char words[][WORDSIZE],int nrOfWords)
{
    for(int i = 0; i < nrOfWords; i++)
    {
        printf("%s, ",words[i]);
    }
        printf("\n");
}