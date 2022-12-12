#include <stdio.h>
#include <string.h>
#define WORDLENGTH 20
#define MAX 10000

struct warehouse
{
    char productName[WORDLENGTH];
    int productNumber;
    int productAmount;
};
typedef struct warehouse Warehouse;

void readFromFile(Warehouse registry[], char fileName[], int *pNrOfProducts);
void readToFile(Warehouse registry[], char fileName[], int *pNrOfProducts);
Warehouse createProduct(char productName[], int productNumber, int productAmount);
void registerProduct(Warehouse registry[], int *pNrOfProducts);
void printProducts(Warehouse p);
void printRegistery(Warehouse registry[], int nrOfProducts);
void searchMenu(Warehouse registry[], int nrOfProducts);
void searchProductNumber(Warehouse registry[], int nrOfProducts);
void searchProductAmount(Warehouse registry[], int nrOfProducts);
void searchProductName(Warehouse registry[], int nrOfProducts);
void editProductAmount(Warehouse registry[], int nrOfProducts);
void sortMenu(Warehouse registry[], int nrOfProducts);
void sortProductName(Warehouse registry[], int nrOfProducts);
void sortProductNumber(Warehouse registry[], int nrOfProducts);
void sortProductAmount(Warehouse registry[], int nrOfProducts);
int deleteProduct(Warehouse registry[], int nrOfProducts);

int main()
{
    Warehouse registry[MAX];
    char fileName[WORDLENGTH];
    int menuChoice, nrOfProducts = 0;
    
    printf("Skriv in namnet pa filen som du vill oppna/skapa: ");
    scanf("%s", fileName);
    readFromFile(registry, fileName, &nrOfProducts);
    do
    {
        printf("\nValj ett menyval (1-7):\n ");
        printf("\n 1. Registrera nya varor \n 2. Skriva ut alla varor \n 3. Soka efter varor \n 4. Andra lagersaldot for varor \n 5. Sortera varor \n 6. Avregistrera varor \n 7. Avsluta programmet\n");
        scanf("%d", &menuChoice);

        switch(menuChoice)
        {
            case 1:
                registerProduct(registry, &nrOfProducts);
                break;
            case 2:
                printRegistery(registry, nrOfProducts);
                break;
            case 3:
                searchMenu(registry, nrOfProducts);
                break;
            case 4:
                editProductAmount(registry, nrOfProducts);
                break;
            case 5:
                sortMenu(registry, nrOfProducts);
                break;
            case 6:
                nrOfProducts = deleteProduct(registry, nrOfProducts);
                break;
            case 7:
                printf("Filen sparades\n");
                printf(">>Bye");
                break;
            default:
                printf("Tillgangliga alternativ (1-7)!\n");
        }
    }while (menuChoice != 7);

readToFile(registry, fileName, &nrOfProducts);

}

void readFromFile(Warehouse registry[], char fileName[], int *pNrOfProducts)
{
    FILE *fp;
    fp = fopen(fileName,"r");

    if(fp!= NULL)
    {
        char productName[WORDLENGTH];
        int productNumber, productAmount;

        while(fscanf(fp, "%s", productName) == 1)
        {
            fscanf(fp, "%d", &productNumber);
            fscanf(fp, "%d", &productAmount);
            if (*pNrOfProducts == MAX)
            {
                break;
            }
            registry[*pNrOfProducts] = createProduct(productName, productNumber, productAmount);
            (*pNrOfProducts)++;
        }
        fclose(fp);
    }
}

void readToFile(Warehouse registry[], char fileName[], int *pNrOfProducts)
{
    FILE *fp;
    fp = fopen(fileName, "w");

    if(fp != NULL)
    {
        for(int i = 0; i < *pNrOfProducts; i++)
        {
            fprintf(fp, "%s\n", registry[i].productName);
            fprintf(fp, "%d\n", registry[i].productNumber);
            fprintf(fp, "%d\n", registry[i].productAmount);
        }
    }
    fclose(fp);
}


Warehouse createProduct(char productName[], int productNumber, int productAmount)
{
    Warehouse p;
    strcpy(p.productName, productName);
    p.productNumber = productNumber;
    p.productAmount = productAmount;
    return p;
}

void registerProduct(Warehouse registry[], int *pNrOfProducts)
{
    int productNumber, productAmount, unique;
    char productName[WORDLENGTH];

    do
    {
        unique = 0;
        if(*pNrOfProducts >= MAX)
        {
            printf("Du har inte mer plats for fler varor\n");
            break;
        }

        printf("Ange varunummer (0 for avslut): ");
        scanf("%d%*c", &productNumber);

        if(productNumber == 0)
        {
            printf("\n");   
            break;
        }
        
        for(int i = 0; i < *pNrOfProducts; i++)
        {
            if(productNumber == registry[i].productNumber)
            {
                printf("Ej unik nummer!\n");
                unique = 1;
            }
        }
    
        if(unique == 0)
        {
            printf("Ange namn: ");
            scanf("%s%*c", productName);
            printf("Ange saldo: ");
            scanf("%d%*c", &productAmount);
            
            registry[*pNrOfProducts] = createProduct(productName, productNumber, productAmount);
            (*pNrOfProducts)++;
        }
    } while (productNumber != 0);
}


void printProducts(Warehouse p)
{
    printf("%03d\t    %-20s%d\n", p.productNumber, p.productName, p.productAmount);
} 

void printRegistery(Warehouse registry[], int nrOfProducts)
{
    if(nrOfProducts == 0)
    {
        printf("Det finns inga varor registerade.\n ");
    }
    else
    {
        printf("Varunummer  Namn                Lagersaldo\n");
        printf("------------------------------------------\n");
        for(int i = 0; i < nrOfProducts; i++)
        {
            printProducts(registry[i]);
        }    
    }
}

void searchMenu(Warehouse registry[], int nrOfProducts)
{
    int menuChoice;
    while(menuChoice != 4)
    {
        printf("\nVad vill du soka efter?\n");
        printf(" 1. Varunummer\n 2. Lagersaldo\n 3. Produktnamn \n 4. Backa ut \n");
        scanf("%d", &menuChoice);

        switch(menuChoice)
        {
            case 1:
                searchProductNumber(registry, nrOfProducts);
                break;
            case 2:
                searchProductAmount(registry, nrOfProducts);
                break;
            case 3:
                searchProductName(registry, nrOfProducts);
                break;
        }
    }
}


void searchProductNumber(Warehouse registry[], int nrOfProducts)
{   
    int userProductNumber, digit_NotFound;
    digit_NotFound = 0;

    while(nrOfProducts <= MAX)
    {
        
        printf("Ange varunummer (0 for avslut): ");
        scanf("%d", &userProductNumber);
        digit_NotFound = 0;
        if(userProductNumber == 0)
        {
            break;
        }

        for(int i=0; i < nrOfProducts; i++)
        {
            if(userProductNumber == registry[i].productNumber)
            {
            printf("Varunummer  Namn                Lagersaldo\n");
            printf("------------------------------------------\n");
            printProducts(registry[i]);
            printf("\n");
            digit_NotFound = 1;
            }
        }
        if(digit_NotFound == 0)
        {
            printf("Kunde inte hitta produkten, forsok igen\n");
        }
    }
}

void searchProductAmount(Warehouse registry[], int nrOfProducts)
{
    int userProductAmount, digit_NotFound;
    

    while(nrOfProducts <= MAX)
    {
        digit_NotFound = 0;
        printf("Ange lagersaldo (0 for avslut): ");
        scanf("%d", &userProductAmount);
        if(userProductAmount == 0)
        {
            break;
        }
        
        printf("Varunummer  Namn                Lagersaldo\n");
        printf("------------------------------------------\n");

        for(int i=0; i != nrOfProducts; i++)
        {
            if(userProductAmount == registry[i].productAmount)
            {

            printProducts(registry[i]);
            }
            else
            {
                digit_NotFound++;
            }   
        }
        if (digit_NotFound == nrOfProducts)
        {
            printf("Kunde inte hitta produkten\n");
        }
    }
}

void searchProductName(Warehouse registry[], int nrOfProducts)
{
    char userProductName[WORDLENGTH]; 
    char *nameSeen;
    while(strcmp(userProductName, "0") != 0)
    {
        printf("Ange produkt namn (0 for avslut): ");
        scanf("%s%*c", userProductName);

        printf("Varunummer  Namn                Lagersaldo\n");
        printf("------------------------------------------\n");

        for(int i = 0; i < nrOfProducts; i++)
        {
            nameSeen = strstr(registry[i].productName, userProductName);
            if(nameSeen != 0)
            {
            printProducts(registry[i]);
            }
        }
    }
}

void editProductAmount(Warehouse registry[], int nrOfProducts)
{
    int userProductNumber, productNotFound = 0, userProductAmount, check;
    char search[WORDLENGTH];

    printf("Vill du soka efter varorna forst? (ja eller nej): ");
    scanf("%s%*c", search);
    if(strcmp(search, "ja") == 0)
    {
        searchMenu(registry, nrOfProducts);
    }

    do
    {   
        check = 0;
        printf("Ange varanummer som du vill andra saldot for (0 f”r avslut): ");
        scanf("%d", &userProductNumber);
        for(int i = 0; i < nrOfProducts; i++)
        {
            if(userProductNumber == registry[i].productNumber)
            {
                printf("Ange andring av lagersaldot: ");
                scanf("%d", &userProductAmount);
                registry[i].productAmount = registry[i].productAmount + userProductAmount;
                check = 1;

                if (registry[i].productAmount < 0)
                {
                    printf("Du kan inte ha negativt lagersaldo, darfor satts den till 0\n");
                    registry[i].productAmount = 0;
                }
            }
        }
            if((check == 0) && (userProductNumber != 0))
            {
                printf("Varan hittades inte, forsok igen.\n");
                productNotFound = 0;
            }     
    } while(userProductNumber != 0);

}

void sortMenu(Warehouse registry[], int nrOfProducts)
{
    int sortMenuChoice;

    do 
    {
        printf("\nVad vill du att din sortning ska vara efter? (1-3)\n");
        printf("1. Varunummer\n2. Lagersaldo\n3. Produkt namn ");
        scanf("%d", &sortMenuChoice);

        switch(sortMenuChoice)
        {
            case 1: 
                sortProductNumber(registry, nrOfProducts);
                break;
            case 2:
                sortProductAmount(registry, nrOfProducts);
                break;
            case 3:
                sortProductName(registry, nrOfProducts);
                break;
            default: 
                printf("\n>>Invalid option, please enter numbers between 1-3<<\n");
        }
    } while(sortMenuChoice != 1 &&  sortMenuChoice != 2 && sortMenuChoice != 3);
}

void sortProductNumber(Warehouse registry[], int nrOfProducts)
{   
    Warehouse temp;
    for(int i = 0; i < nrOfProducts - 1;i++)
    {
        for(int j = 0; j < nrOfProducts - 1 - i; j++)
        {
            if(registry[j].productNumber > registry[j+1].productNumber)
            {
                temp = registry[j];
                registry[j] = registry[j+1];
                registry[j+1] = temp;
            }
        }   
    }
}

void sortProductAmount(Warehouse registry[], int nrOfProducts)
{
    Warehouse temp;
    for(int i = 0; i < nrOfProducts - 1;i++)
    {
        for(int j = 0; j < nrOfProducts - 1 - i; j++)
        {
            if(registry[j].productAmount > registry[j+1].productAmount)
            {
                temp = registry[j];
                registry[j] = registry[j+1];
                registry[j+1] = temp;
            }
        }   
    }
}

void sortProductName(Warehouse registry[], int nrOfProducts)
{
    Warehouse temp;
    for(int i = 0; i < nrOfProducts - 1;i++)
    {
        for(int j = 0; j < nrOfProducts - 1 - i; j++)
        {
            if(strcmp(registry[j].productName, registry[j+1].productName) > 0)
            {
                temp = registry[j];
                registry[j] = registry[j+1];
                registry[j+1] = temp;
            }
        }   
    }
}

int deleteProduct(Warehouse registry[], int nrOfProducts)
{
    int deleteInput;
    int i;
    char search[WORDLENGTH];

    printf("Vill du soka efter varorna forst? (ja eller nej): ");
    scanf("%s%*c", search);
    if(strcmp(search, "ja") == 0)
    {
    searchMenu(registry, nrOfProducts);
    }
    
    do
    {
        printf("Skriv varunummret av varan som du vill avregistera (0 for avslut): ");
        scanf("%d", &deleteInput);

        for( i = 0; i < nrOfProducts; i++)
        {
            if(deleteInput == registry[i].productNumber)
            {
                for(int j = i; j < nrOfProducts - 1; j++)
                {
                    registry[j] = registry[j+1];
                }
                nrOfProducts--;
            }
        }
        printf("\nNy lagerstatus :\n");
        printRegistery(registry, nrOfProducts);
    } while(deleteInput != 0);


    return nrOfProducts;
}



