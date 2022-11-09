#include <stdio.h>
#include <string.h>
#define WORDLENGTH 20
#define MAX 5

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
void searchProductName(Warehouse registry[], int nrOfProducts);
void editProductAmount(Warehouse registry[], int nrOfProducts);
void sortMenu(Warehouse registry[], int nrOfProducts);
void sortProductName(Warehouse registry[], int nrOfProducts);
void sortProductNumber(Warehouse registry[], int nrOfProducts);
void sortProductAmount(Warehouse registry[], int nrOfProducts);
int deleteProduct(Warehouse registry[], int nrOfProduct);




int main()
{
    int menuChoice, nrOfProducts = 0;
    Warehouse itemList[MAX], registry[MAX];

    while (menuChoice != 7)
    {
        printf("\nValj en meny val (1-7):\n ");
        printf("\n 1. Registrera nya varor \n 2. Skriva ut alla varor \n 3. Soka efter varor \n 4. Andra lagersaldot f?r varor \n 5. Sortera varor \n 6. Avregistrera varor \n 7. Avsluta programmet\n");
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
                editProductAmount(itemList, nrOfProducts);
                break;
            case 5:
                sortMenu(itemList, nrOfProducts);
                break;
            case 6:
                nrOfProducts = deleteProduct(itemList, nrOfProducts);
                break;
            case 7:
                printf(">>Bye");
                break;
                // avsluta programmet
            default:
                printf("Tillgangliga alternativ (1-7)!\n");
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
        

        if(*pNrOfProducts >= MAX)
        {
            printf("Du har inte mer plats for fler varor\n");
            break;
        }
        printf("Ange varunummer (0 f”r avslut): ");
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
                unique=1;

            }else{
                unique=0;
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
    if(nrOfProducts == 0)
    {
        printf("Det finns inga varor registerade. ");
    }
    else
    {
        printf("VARUNUMMER      NAMN        LAGERSALDO\n");
        printf("--------------------------------------\n");
        for(int i = 0; i < nrOfProducts; i++)
        {
            printProducts(registry[i]);
        }    
    }
}

void searchMenu(Warehouse registry[], int nrOfProducts)
{
    int menuChoice, userProductNumber, userProductName, userProductAmount;
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
    int userProductNumber, productNumber, productAmount, digit_NotFound;
    char productName[WORDLENGTH];

    while(nrOfProducts <= MAX)
    {
        digit_NotFound = 0;
        printf("Ange varunummer (0 f”r avslut): ");
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
            printf("Kunde inte hitta produkten, forsok igen\n");
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
        printf("Ange lagersaldo (0 f”r avslut): ");
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
                printf("%03d\t\t\t%s\t\t%d\n", registry[i].productNumber, registry[i].productName, registry[i].productAmount);
            }
        }
    }
}

void searchProductName(Warehouse registry[], int nrOfProducts)
{
    int productNumber, productAmount;
    char productName[WORDLENGTH], userProductName[WORDLENGTH];
    char *nameSeen;
    while(strcmp(userProductName, "0") != 0)
    //while(userProductName != '0')
    {
        printf("Ange produkt namn (0 for avslut): ");
        scanf("%s%*c", userProductName);

        for(int i = 0; i < nrOfProducts; i++)
        {
            nameSeen = strstr(registry[i].productName, userProductName);
            if(nameSeen != 0)
            {
                printf("%03d\t\t\t%s\t\t%d\n", registry[i].productNumber, registry[i].productName, registry[i].productAmount);
            }
        }
    }
   
}

void editProductAmount(Warehouse registry[], int nrOfProducts)
{
    int productNumber, productAmount, userProductNumber, productNotFound = 0, userProductAmount;
    char productName[WORDLENGTH];

    searchMenu(registry, nrOfProducts);

    while(userProductNumber != 0)
    {   
        printf("Ange varanummer som du vill andra saldot f”r: ");
        scanf("%d", &userProductNumber);
        for(int i = 0; i < nrOfProducts; i++)
        {
            
            if(userProductNumber != registry[i].productNumber)
            {
                productNotFound++;
            }
            else if(userProductNumber == registry[i].productNumber)
            {
                printf("Skriv in nya lagersaldot: ");
                scanf("%d", &userProductAmount);
                registry[i].productAmount = registry[i].productAmount + userProductAmount;
                if (registry[i].productAmount < 0)
                {
                    printf("Du kan inte ha negativt lagersaldo, darfor satts den till 0\n");
                    registry[i].productAmount = 0;
                }
            }
            if(productNotFound == nrOfProducts)
            {
                printf("Varan hittades inte, f”rs”k igen.\n");
                productNotFound = 0;
            }     
        }
    }
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
    printf(">>Sorterade efter varunummer<<\n");
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
    printf(">>Sorterade efter lagersaldo<<\n");
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
    printf(">>Sorterade efter produkt namn<<\n");
}

int deleteProduct(Warehouse registry[], int nrOfProducts)
{
    int deleteInput;
    int i;

    //searchMenu(registry, nrOfProducts);

    do
    {
        printf("Skriv varunummret av varan som du vill avregistera (0 f”r avslut): ");
        scanf("%d", &deleteInput);

        for( i = 0; i < nrOfProducts; i++)
        {
            if(deleteInput == registry[i].productNumber)
            {
                for(int j = i; j < nrOfProducts; j++)
                {
                    registry[j] = registry[j+1];
                }
                nrOfProducts--;
            }
        }
        printf("Nya lager status :\n");
        printRegistery(registry, nrOfProducts);
    } while(deleteInput != 0);


    return nrOfProducts;
}



