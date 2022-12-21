#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50
#define NRDICE 3

void printTaken(int taken[]);
int result(int taken[]);
int playRound(int taken[]);
int throwDie();
int evaluateExp(int dice[], char op1, char op2);
int evalOp(int nr1,char op,int nr2);

int main(){

    int taken[MAX]={0};
    char choice='k';
    srand(time(NULL));

    while(choice!='a')
    {
        printf("Foljande tal 1-49 ar upptagna:");
        printTaken(taken);
        printf("Vill du kasta tarningar (k) eller avsluta (a): ");
        scanf("%c%*c",&choice);
        if(choice=='a'){
            printf("Du fick %d\n",result(taken));
        }
        if(choice=='k'){
            if(!playRound(taken))
            {
                printf("Du misslyckades och far 0p\n");
                break;
            }
        }
    }
    return 0;
}

int playRound(int taken[])
{
    int dice[NRDICE];
    char operator1, operator2;
    printf("Du fick ");
    for(int i=0;i<NRDICE;i++)
    {
        dice[i]=throwDie();
        printf("%d, ",dice[i]);
    }
    printf("\n");

    printf("Vilka tva raknesatt vill du anvanda? (+, -, *, /): ");
    scanf(" %c %c%*c",&operator1,&operator2);
    int result = evaluateExp(dice,operator1,operator2);
    printf("Resultat: %d\n",result);

    if(result<1||result>49)
        return 0;
    if(taken[result])
        return 0;
    taken[result]=1;
    return 1;
}

int evaluateExp(int dice[], char op1, char op2)
{
    return evalOp(evalOp(dice[0],op1,dice[1]),op2,dice[2]);
}

int evalOp(int nr1,char op,int nr2)
{
    switch(op){
        case '+': return nr1+nr2;
        case '-': return nr1-nr2;
        case '*': return nr1*nr2;
        case '/': return nr1/nr2;
    }
    return -1;
}

int throwDie()
{
    return rand()%6+1;
}

int result(int taken[])
{
    int sum=0;
    for(int i=1;i<MAX;i++)
    {
        if(taken[i])
        {
            sum+=i;
        }
    }
    return sum;
}

void printTaken(int taken[])
{
    for(int i=1;i<MAX;i++)
    {
        if(taken[i])
            printf("%d, ",i);
    }
    printf("\n");
}