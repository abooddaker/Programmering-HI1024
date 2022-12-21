#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAXCHAR 20
#define MAXPATIENTS 10

struct patients
{
    char lastName[MAXCHAR];
    int date;
    float temp;
}; typedef struct patients Patients;

void registerPatient(Patients registry[], int *pNrOfPatients);
void printAllPatients(Patients registry[], int nrOfPatients);
void deletePatient(Patients registry[], int *pNrOfPatients);

int main(void)
{
    int menuChoice, nrOfPatients = 0;
    Patients registry[MAXPATIENTS];

    do
    {
        printf("(1) Registrera (2) Skriva ut (3) Radera (4) Avsluta: ");
        scanf("%d", &menuChoice);
        
        switch(menuChoice)
        {
            case 1: registerPatient(registry,&nrOfPatients);
            break;
            case 2: printAllPatients(registry,nrOfPatients); //skriva ut alla
            break;
            case 3: deletePatient(registry,&nrOfPatients);
            break;

        }
    } while(menuChoice != 4);
    printf("Avslutar!");
}

void registerPatient(Patients registry[], int *pNrOfPatients)
{
    if((*pNrOfPatients) == MAXPATIENTS )
    {
        printf("Det finns inga mer platser f”r mer patienter.");
        return;
    }
    printf("Ange efternamn: ");
    scanf(" %s", registry[*pNrOfPatients].lastName);

    printf("Ange inskrivningsdatum: ");
    scanf(" %d", &registry[*pNrOfPatients].date);
    
    printf("Ange temp: ");
    scanf("%f", &registry[*pNrOfPatients].temp);
    (*pNrOfPatients)++;
}

void printAllPatients(Patients registry[], int nrOfPatients)
{
    if(nrOfPatients == 0)
    {
        printf("Registret tomt.\n");
        return;
    }
    for(int i = 0; i < nrOfPatients; i++)
    {
        printf("%s, %d, temp: %.1f\n", registry[i].lastName, registry[i].date, registry[i].temp);
    }
}

void deletePatient(Patients registry[], int *pNrOfPatients)
{
    char name[MAXCHAR];
    int patientFound = 0; 

    printf("Ange patients namn att radera: ");
    scanf(" %s", name);

    for(int i = 0; i < (*pNrOfPatients); i++)
    {
        if(strcmp(name, registry[i].lastName) == 0)
        {
            printf("Patient %s raderades.\n", registry[i].lastName);
            patientFound = 1;

            for(int j = i; j < *pNrOfPatients; j++)
            {
                registry[j] = registry[j+1];
                //strcpy(registry[i].lastName, registry[i+1].lastName);
            }
            (*pNrOfPatients)--;
        }
    }
    //if (count == (*pNrOfPatients))
    if(patientFound == 0)
    {
        printf("Patient hittades inte.\n");
    }
}

