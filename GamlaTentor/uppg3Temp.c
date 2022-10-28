#include <stdio.h>
#include <string.h>
#define MAXCHAR 20
#define MAXNRTEMPS 10

struct temperatures{
    char date[MAXCHAR];
    float data[MAXNRTEMPS];
    int nrOfData;
};
typedef struct temperatures Temperatures;

void printTemp(Temperatures t);
 //void concatenate(Temperatures *t1, Temperatures *t2);

int  main(){
    Temperatures temperatures1 = {"2021-06-27",{18.7, 19.2, 18.3},3};
    printTemp(temperatures1);
    Temperatures temperatures2 = {"2021-06-27",{22.1, 23.4},2};
    //concatenate(&temperatures1,&temperatures2);
    printTemp(temperatures1);
    return 0;
}

/*void concatenate(Temperatures *t1, Temperatures *t2){
    if(strcmp(t1->date,t2->date)!=0)
        return;
    for(int i=0;i<t2->nrOfData;i++){
        if(t1->nrOfData==MAXNRTEMPS) return;
        t1->data[t1->nrOfData]=t2->data[i];
        (t1->nrOfData)++;
    }
}
*/
void printTemp(Temperatures t)
{
    printf("%s ",t.date);
    for(int i=0;i<t.nrOfData;i++)
    {
        printf("%.1f, ",t.data[i]);
    }
    printf("\n");
}