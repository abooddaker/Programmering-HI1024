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

void registerProduct(Warehouse itemList[], int *pNrOfProducts)
{
    int productNumber, productAmount;
    char productName[WORDLENGTH];
    while (productNumber != 0)
    {
        printf("Ange varunummer (0 f”r avslut): ");
        scanf("%d%*c", &productNumber);
        if(productNumber == 0)
        break;
        printf("Ange namn: ", productName);
        scanf("%s%*c", productName);
        printf("Ange saldo: ", productAmount);
        scanf("%d%*c", &productAmount);
        
        (*pNrOfProducts++);

    } 
}

/* void regCars(Car reg[],int *pNrOfCars)
{
    char again[WORDLENGTH] = "ja", model[WORDLENGTH];
    int year,milage;
    while (strcmp(again, "ja") == 0)
    { 
        printf("Ange model: ");
        scanf("%s%*c",model);
        printf("Ange year: ");
        scanf("%d%*c",&year);
        printf("Ange milage: ");
        scanf("%d%*c",&milage);
        reg[*pNrOfCars] = createCar(model,year,milage);
        (*pNrOfCars)++;
        printf("Vill du fortsatta? (ja eller nej) ");
        scanf("%s%*c",again);
    }
}
*/

int main()
{
    int menuChoice, nrOfProducts;
    Warehouse itemList[MAX];
    
    while (menuChoice != 7)
    {
        printf("V„lj en meny val (1-7): ");
        printf("1. Registrera nya varor \n 2. Skriva ut alla varor \n 3. Soka efter varor \n 4. Andra lagersaldot f”r varor \n 5. Sortera varor \n 6. Avregistrera varor \n 7. Avsluta programmet ");
        scanf("%d", &menuChoice);

        switch(menuChoice)
        {
            case 1:
                registerProduct(itemList, &nrOfProducts);
            case 2:
                // skriva ut
            case 3:
                // s”ka efter
            case 4:
                // lagersaldot 
            case 5:
                // sortera efter varunummer
            case 6:
                // avregistera varor
            case 7:
                break;
                // avsluta programmet
        }
    }
}