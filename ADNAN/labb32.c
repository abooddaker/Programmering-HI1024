#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LANGD 20 + 1
#define MAX 10000

struct vara
{
    int varuNr;
    char namn[LANGD];
    int lagerSaldo;
};
typedef struct vara Vara;

int registeraVaror(Vara lista[], int antalVaror);
void utskriftAvVaror(Vara lista[], int antalVaror);
void sort(Vara lista[],int antalVaror); 
void sokaVaror(Vara lista[],int antalVaror);
void sokVaruNr(Vara lista[], int antalVaror);
void sokVarunamn(Vara lista[], int antalVaror);
void sokLagerSaldo(Vara lista[], int antalVaror);
void AndraLagerSaldo(Vara lista[], int antalVaror);
void avregistreraVaror(Vara lista[], int *antalVaror);
void sattaIOrdning(Vara lista[], int j);
void skrivaTillFil(Vara lista[], char filnamn[], int *antalVaror);
void lasaAvFil(Vara lista[], char filnamn[], int *antalVaror);

int main()
{
   int menyNr, run=1, antalVaror=0;
   Vara varolista[MAX];
   char filnamn[10];

   printf("Vilken fil vill du hamta? Skriv namnet pa den: ");
   scanf("%s", filnamn);
   printf("\n");
   
   lasaAvFil(varolista, filnamn, &antalVaror);

    while (run!=0)
    {
        printf("1. Registera nya varor          \n");
        printf("2. Skriva ut alla varor         \n");
        printf("3. Soka efter varor             \n");
        printf("4. Andra lagersaldot for varor  \n");
        printf("5. Sortera varor                \n");
        printf("6. Avregistera varor            \n");
        printf("7. Avsluta programmet         \n\n");
        printf("Valj av menyn! (1-7): ");
        scanf("%d", &menyNr);

        switch (menyNr)
        {
        case 1:
            antalVaror = registeraVaror(varolista, antalVaror);
            break;
        case 2:
            utskriftAvVaror(varolista, antalVaror);
            break;
        case 3:
            sokaVaror(varolista, antalVaror);
            break;
        case 4:
            AndraLagerSaldo(varolista, antalVaror);
            break;
        case 5:
            sort(varolista, antalVaror);
            break;
        case 6:
            avregistreraVaror(varolista, &antalVaror);
            break;
        case 7:
            skrivaTillFil(varolista, filnamn, &antalVaror);
            run=0;
            break;
        default:
            printf("\n***Skriv in ett giltigt nummer!***\n\n");
            break;
        }
    }

    return 0;
}

int registeraVaror(Vara lista[], int antalVaror)
{
    Vara tempVara;
    int run=1, a, b=0;

    while (run)
    {
        if (antalVaror<=MAX)
        {
            a=0;

            if (antalVaror==MAX)
            {
                printf("\n***listan ar full!***\n\n");
                break;
            }
            
            printf("Ange varunummer (0 for avslut): ");
            scanf("%d%*c", &tempVara.varuNr);

            if (tempVara.varuNr==0)
            {
                printf("\n");
                break;
            }

            for (int j = 0; j < antalVaror; j++)
            {
                if (tempVara.varuNr==lista[j].varuNr)
                {
                    printf("Ej unikt nummer!\n");
                    a = 1;
                }
            }

            if (a==0)
            {
                printf("Ange namn: ");
                scanf("%s%*c", tempVara.namn);

                if (LANGD < strlen(tempVara.namn))
                {
                    printf("\n***For stort namn!***\n\n");
                    break;
                }
                else
                {
                    b=1;
                }
            }
            
            if ((b==1) && (a == 0))
            {
                printf("Ange saldo: ");
                scanf("%d%*c", &tempVara.lagerSaldo);

                for (int i = antalVaror; i < MAX; i++)
                {   
                    lista[i]=tempVara;
                    break;
                }

                antalVaror++;
            }
        }
        else
        {
            printf("\n***listan ar full!***\n\n");
            run = 0;
        }
    }
    return antalVaror;  

}

void utskriftAvVaror(Vara lista[], int antalVaror)
{
    if (antalVaror > 0)
    {
        printf("_________________________________________\n\n");
        printf("Varunummer     Namn                 Saldo \n");
        printf("_________________________________________\n");

        for (int i = 0; i < antalVaror; i++)
        {
            printf("%03d            %-20s %-8d\n", lista[i].varuNr, lista[i].namn, lista[i].lagerSaldo);
        }

        printf("\n");
    }
    else
    {
        printf("\n***Listan ar tom!***\n\n");
    }   
}

void sokaVaror(Vara lista[], int antalVaror)
{
    int val=5, run=0;

    while (run!=1)
    {
        if (val==5)
        {
            printf("\nVad vill du soka efter?\n");
            printf("1.Varunummer \n");
            printf("2.Varunamn   \n");
            printf("3.Lagersaldo \n");
            printf("4. Avsluta   \n");
            printf("Val (1-4): ");
            scanf("%d", &val);
        }

        switch (val)
        {
        case 1:
            sokVaruNr(lista, antalVaror);
            val=5;
            break;
        case 2:
            sokVarunamn(lista, antalVaror);
            val=5;
            break;
        case 3:
            sokLagerSaldo(lista, antalVaror);
            val=5;
            break;
        case 4:
            run=1;
            break;
        default:
            printf("\n***Skriv in ett giltigt nummer!***");
            val=5;
            break;
        }

        printf("\n");
        
    }
}

void sokVaruNr(Vara lista[], int antalVaror)
{
    int test=1, run=0, a=0;
    
    while (run!=1)
    {
        printf("\nskriv varunummret (0 for avsluta): ");
        scanf("%d", &test);

        if (test ==0)
        {
            run=1;
            break;
        }
        
        for(int j=0 ; j < antalVaror ; j++) 
        {
            if(test == lista[j].varuNr)
            {
                printf("%03d            %-20s %-8d", lista[j].varuNr, lista[j].namn, lista[j].lagerSaldo);
                run=1;
                a=1;
                break;
            }
            else
            {
                a++;
            }
        }

        if (a==antalVaror)
        {
            printf("\n***Varan finns ej!***\n");
        }
    }
}

void sokVarunamn(Vara lista[], int antalVaror)
{
    char test[LANGD];
    
    printf("\nskriv varunamnet (0 for avsluta): ");
    scanf("%s", test);

    for(int j=0 ; j < antalVaror ; j++) 
    {
        if(strstr(lista[j].namn, test)!=NULL)  
        {
           printf("%03d            %-20s %-8d\n", lista[j].varuNr, lista[j].namn, lista[j].lagerSaldo);
        }
    }
}

void sokLagerSaldo(Vara lista[], int antalVaror)
{
    int test=1;

    printf("\nskriv lagersaldot (0 for avsluta): ");
    scanf("%d", &test);

    for(int j=0 ; j < antalVaror ; j++) 
    {
        if(test == lista[j].lagerSaldo)
        {
            printf("%03d            %-20s %-8d\n", lista[j].varuNr, lista[j].namn, lista[j].lagerSaldo);
        }
    }
}

void AndraLagerSaldo(Vara lista[], int antalVaror)
{
    int saldoNummer;
    int varuNummer;
    int val=5, run=0, a=0;

    while (run!=1)
    {
        sokaVaror(lista, antalVaror);

        if (val==5)
        {
            printf("vilken vara vill du andra lager saldott på? (Ange varunummer eller 0 for avsluta): ");
            scanf("%d", &varuNummer);
        }        

        for(int i=0 ; i < antalVaror ; i++) 
            {
                if(varuNummer != lista[i].varuNr)
                {
                    a++;
                }
            }
        
        if (a==antalVaror)
        {
            printf("\n***Varan finns inte!***\n");
            continue;
        }
                    
        while (varuNummer != 0)
        {
            printf("skriv med hur mycket du vill andra: ");
            scanf("%d", &saldoNummer);            

            for(int i=0 ; i < antalVaror ; i++) 
            {
                if(varuNummer == lista[i].varuNr)
                {
                    lista[i].lagerSaldo=lista[i].lagerSaldo + saldoNummer;

                    if (lista[i].lagerSaldo < 0)
                    {
                        lista[i].lagerSaldo=0;
                        printf("\n***Lagersaldot har minskats till mindre an noll och satts till noll!***\n");
                        break;
                    }
                    
                }
                else
                {
                    a++;
                }
            }
            break;
        }

        if (varuNummer==0)
        {
            run=1;
        }
    }
}

void sort(Vara lista[], int antalVaror)
{
    int val=5, run=0;

    while (run!=1)
    {
        if (val==5)
        {
            printf("Hur du vill sortera varorna efter?\n");
            printf("1.Varunummer \n");
            printf("2.Varunamn   \n");
            printf("3.Lagersaldo \n");
            printf("4. Avsluta   \n");
            printf("Val (1-4): ");
            scanf("%d", &val);
        }

        switch (val)
        {
        case 1:
            for(int i=0 ; i < antalVaror-1 ; i++)
            {  
                for(int j=0 ; j < antalVaror-1-i ; j++)
                {
                    if(lista[j].varuNr > lista[j+1].varuNr)
                    {
                        sattaIOrdning(lista, j);
                    }
                }
            }
            run=1;
            break;

        case 2:
            for(int i=0 ; i < antalVaror-1 ; i++)
            {  
                for(int j=0 ; j < antalVaror-1-i ; j++)
                {
                    if(strcmp(lista[j].namn,lista[j+1].namn)>0)
                    {
                        sattaIOrdning(lista, j);
                    }
                }
            }

            run=1;
            break;

        case 3:
            for(int i=0 ; i < antalVaror-1 ; i++)
            {  
                for(int j=0 ; j < antalVaror-1-i ; j++)
                {
                    if(lista[j].lagerSaldo > lista[j+1].lagerSaldo)
                    {
                        sattaIOrdning(lista, j);
                    }
                }
            }

            run=1;
            break;
        case 4:
            run=1;
            break;
        
        default:
            printf("\n***Skriv in ett giltigt nummer!***\n");
            val=5;
            break;//LAGT TILL!!
        }

        printf("\n");
    }
    
}

void sattaIOrdning(Vara lista[], int j)
{
    Vara tmp;
    
    tmp = lista[j];
    lista[j] = lista[j+1];
    lista[j+1] = tmp;
}

void avregistreraVaror(Vara lista[], int *antalVaror)
{
    int varuNummer=1;
    int i, run=0, a=0;

    if (antalVaror > 0)
    {
        while (run!=1)
        {
            sokaVaror(lista, *antalVaror);

            printf("Ange varunummer for varan du vill ta bort: (0 for avsluta) ");
            scanf("%d", &varuNummer);

            if (varuNummer==0)
            {
                run=1;
                break;
            }
            
            while (varuNummer!=0)
            {
                for ( i = 0; i < *antalVaror; i++)
                {
                    if (varuNummer != lista[i].varuNr)
                    {
                        a++;
                    }
                    else
                    {
                        break;
                    }
                }

                if (a==*antalVaror)
                {
                    printf("\n***Varunummret frinns ej!***\n");
                    break;
                }
                
                for ( int j = i; j < *antalVaror; j++)
                {
                    lista[j]= lista[j+1];

                }             
                
                (*antalVaror)--; 
                varuNummer=0;
            }
            
        }

    }
    else
    {
        printf("\n***Finns inga varor att avregistrera!***\n\n");
    }
    
    
}

void skrivaTillFil(Vara lista[], char filnamn[], int *antalVaror)
{
    FILE *fil;
    fil = fopen(filnamn, "w");

    if (fil!=NULL)
    {
        for (int i = 0; i < *antalVaror; i++)
        {
            if (i==*antalVaror-1)
            {
                fprintf(fil, "%d %20s %d", lista[i].varuNr, lista[i].namn, lista[i].lagerSaldo);
            }
            else
            {
                fprintf(fil, "%d %20s %d\n", lista[i].varuNr, lista[i].namn, lista[i].lagerSaldo);
            }
            
        }
        
    }
    fclose(fil);   
}

void lasaAvFil(Vara lista[], char filnamn[], int *antalVaror)
{
    Vara tmpVara;
    FILE *fil;
    fil = fopen(filnamn, "r");
    int i = 0;

    if (fil == NULL)
    {
        fil = fopen(filnamn, "w");
    }
    else
    {

    fseek(fil, 0, SEEK_END);
    if (ftell(fil) != 0) {
        fseek(fil, 0, SEEK_SET);
        while (!feof(fil)) {
            fscanf(fil, "%d %20s %d", &tmpVara.varuNr, tmpVara.namn, &tmpVara.lagerSaldo);
            lista[i] = tmpVara;
            i++;
            (*antalVaror)++;
            if (MAX == i)
            {
                break;
            };
        }
    }

    }
    fclose(fil);
}
