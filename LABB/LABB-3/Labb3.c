#include <stdio.h>
#include <string.h>
#define WORDLENGTH 20
#define MAX 3

struct warehouse
{
    char productName[WORDLENGTH];
    int productNumber;
    int productAmount;
};
typedef struct warehouse Warehouse;

Warehouse createProduct(char productName[], int productNumber, int productAmount);
void registerProduct(Warehouse registry[], int *pNrOfProducts);
void printProducts(Warehouse p);
void printRegistery(Warehouse registry[], int nrOfProducts);
void searchMenu(Warehouse registry[], int nrOfProducts);
void searchProductNumber(Warehouse registry[], int nrOfProducts);
void searchProductAmount(Warehouse registry[], int nrOfProducts);





int main()
{
    int menuChoice, nrOfProducts = 0;
    Warehouse itemList[MAX], registry[MAX];

    while (menuChoice != 7)
    {
        printf("\nV„lj en meny val (1-7):\n ");
        printf("\n 1. Registrera nya varor \n 2. Skriva ut alla varor \n 3. Soka efter varor \n 4. Andra lagersaldot f”r varor \n 5. Sortera varor \n 6. Avregistrera varor \n 7. Avsluta programmet\n");
        scanf("%d", &menuChoice);

        switch(menuChoice)
        {
            case 1:
                registerProduct(itemList, &nrOfProducts);
                break;
            case 2:
                printRegistery(itemList, nrOfProducts);
                break;
            case 3:
                searchMenu(itemList, nrOfProducts);
                break;
            case 4:
                // lagersaldot 
            case 5:
                // sortera efter varunummer
            case 6:
                // avregistera varor
            case 7:
                break;
                // avsluta programmet
            default:
                printf("Tillg„ngliga alternativ (1-7)!\n");
        }
    }
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
    int productNumber, productAmount, unique = 0;
    char productName[WORDLENGTH];

    while (productNumber != 0) //&& *pNrOfProducts < MAX)
    {
        unique = 0;

        if(*pNrOfProducts >= MAX)
        {
            printf("Du har inte mer plats for fler varor\n");
            break;
        }
        printf("Ange varunummer (0 f”r avslut): ");
        scanf("%d%*c", &productNumber);

        if(productNumber == 0)
        {
            break;
        }
        
        for(int i = 0; i < *pNrOfProducts; i++)
        {
            if(productNumber == registry[i].productNumber)
            {
                printf("Ej unik nummer!\n");
                unique++;
                printf("%d", unique);
            }
        }
        if(unique == 0)
        {
            printf("Ange namn: ", productName);
            scanf("%s%*c", productName);
            printf("Ange saldo: ", productAmount);
            scanf("%d%*c", &productAmount);
            
            registry[*pNrOfProducts] = createProduct(productName, productNumber, productAmount);
            (*pNrOfProducts)++;
        }
        
    } 
}

void printProducts(Warehouse p)
{
    printf("%03d            %s  %5d\n", p.productNumber, p.productName, p.productAmount);
} 

void printRegistery(Warehouse registry[], int nrOfProducts)
{
    printf("VARUNUMMER      NAMN        LAGERSALDO\n");
    printf("--------------------------------------\n");
    for(int i = 0; i < nrOfProducts; i++)
    {
        printProducts(registry[i]);
    }
}

void searchMenu(Warehouse registry[], int nrOfProducts)
{
    int menuChoice, userProductNumber, userProductName, userProductAmount;
    while(menuChoice != 4)
    {
        printf("\nVilken vill du s”ka efter?\n");
        printf(" 1. Varunummer\n 2. Lagersaldo\n 3. Produktnamn \n 4. Tillbaka till meny ");
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
                break;
        }
    }
}


void searchProductNumber(Warehouse registry[], int nrOfProducts)
{   
    int userProductNumber, productNumber, productAmount, digit_NotFound;
    char productName[WORDLENGTH];

    while(nrOfProducts <= MAX)
    {
        digit_NotFound = 0;
        printf("Ange varunummer: ");
        scanf("%d", &userProductNumber);
        if(userProductNumber == 0)
        {
            break;
        }
        for(int i=0; i != nrOfProducts; i++)
        {
            if(userProductNumber == registry[i].productNumber)
            {
                printf("Varunummer     Namn     Lagersaldo\n");
                printf("----------------------------------\n");
                printf("%03d             %s       %d\n", registry[i].productNumber, registry[i].productName, registry[i].productAmount);
            }
            else
            {
                digit_NotFound++;
            }
        }
        if(digit_NotFound == nrOfProducts)
        {
            printf("Kunde inte hitta produkten, f”rs”k igen\n");
        }
    }
}

void searchProductAmount(Warehouse registry[], int nrOfProducts)
{
    int userProductAmount, productNumber, productAmount, digit_NotFound;
    char productName[WORDLENGTH];

    while(nrOfProducts <= MAX)
    {
        digit_NotFound = 0;
        printf("Ange lagersaldo: ");
        scanf("%d", &userProductAmount);
        if(userProductAmount == 0)
        {
            break;
        }
            printf("Varunummer     Namn     Lagersaldo\n");
            printf("----------------------------------\n");
        for(int i=0; i != nrOfProducts; i++)
        {
            if(userProductAmount == registry[i].productAmount)
            {
                printf("%03d             %s       %d\n", registry[i].productNumber, registry[i].productName, registry[i].productAmount);
            }
        }
    }
}
