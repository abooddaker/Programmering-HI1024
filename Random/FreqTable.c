#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 7

int getNrOfDice();
void createFreqTable(int freq[],int nrThrows);
void fillWithZeros(int v[], int n);
void printArray(int v[], int n);
int throwDice();
void printFreqTable(int freq[], int size);

int main(){

    int nrOfThrows;
    int freqTable[SIZE];
    srand(time(NULL));
    nrOfThrows = getNrOfDice();
    createFreqTable(freqTable,nrOfThrows);
    printFreqTable(freqTable, SIZE);
    return 0;
}

void printFreqTable(int freq[], int size){
    printArray(freq,SIZE);
}

void createFreqTable(int freq[],int nrThrows){
    int result;
    fillWithZeros(freq,SIZE);
    for(int i=0;i<nrThrows;i++){
        result = throwDice();
        freq[result]++;
    }
}

int throwDice(){
    return rand()%6+1;
}

void fillWithZeros(int v[], int n){
    for(int i=0;i<n;i++){
        v[i] = 0;
    }
}

void printArray(int v[], int n){
    for(int i=0;i<n;i++){
        printf("%d, ",v[i]);
    }
    printf("\n");
}

int getNrOfDice(){
    int nrThrows;
    printf("Hur manga kast vill du gora? ");
    scanf("%d",&nrThrows);
    return nrThrows;
}