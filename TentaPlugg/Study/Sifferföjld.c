#include <stdio.h>
#include <string.h>
#define MAX 101

void mode(char digits[]);
void printArray(int a[],int n);
void longestSeq(char digits[]);

int main(){
    char digits[MAX];
    printf("Ange sifferfoljd: ");
    scanf("%[^\n]%*c",digits);
    while(strlen(digits)!=1||digits[0]!='0')
    {
        mode(digits);
        longestSeq(digits);
        printf("Ange sifferfoljd: ");
        scanf("%[^\n]%*c",digits);
    }
    printf("Avslutar\n");
    return 0;
}

void longestSeq(char digits[])
{
    int i=1,currentSeq=1,bestSeq=1,bestSeqEndPos=0;
    while(digits[i]!=0)
    {
        if(digits[i]-'0'>digits[i-1]-'0')
        {
            currentSeq++;
            if(currentSeq>bestSeq)
            {
                bestSeq=currentSeq;
                bestSeqEndPos=i;
            }
        }
        else
        {
            currentSeq=1;
        }
        i++;
    }
    printf("Langsta stigande sekvens ar %d lang och finns pa position %d till %d\n",
        bestSeq,bestSeqEndPos-bestSeq+1,bestSeqEndPos);
}

void mode(char digits[])
{
    int count[10]={0};
    int i=0;
    while(digits[i]!=0)
    {
        count[digits[i++]-'0']++;
    }
    int max=0;
    for(i=0;i<10;i++)
    {
        if(max<count[i]) max=count[i];
    }
    printf("Typvarde: ");
    for(i=0;i<10;i++)
    {
        if(count[i]==max) printf("%d, ",i);
    }
    printf("\n");
}

void printArray(int a[],int n)
{
    for(int i=0;i<n;i++) printf("%d, ",a[i]);
    printf("\n");
}