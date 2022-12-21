#include <stdio.h>
#include <string.h>

struct bankAccount {
    char name[15];
    int accountNumber;
    int balance;
}; typedef struct bankAccount Bank;

Bank createAccount(char name[15], int accountNumber, int balance);
void printAccount(Bank b);
void transfer(Bank *acc1, Bank *acc2);
void printAllAccounts(Bank account[], int totalAcc);


int main(void)
{
    Bank account1 = {"Shevek", 123, 230}; 
    Bank account2;
    account2 = createAccount("Ketho", 124, 300);
    Bank account3 = createAccount("Ray", 125, 350);
    Bank account4 = createAccount("Me", 126, 500);
    Bank account5 = createAccount("Me", 126, 500);


    printAccount(account1);
    printAccount(account2);

    transfer(&account1, &account2);

    printAccount(account1);
    printAccount(account2);

    Bank accounts[5] = {account1, account2, account3, account4, account5};
    int totalAcc = 5;

    printf("-----------\n");
    printAllAccounts(accounts, totalAcc);

    return 0;
}

void printAccount(Bank b)
{
    printf("%s, %d, %dkr\n", b.name, b.accountNumber, b.balance);
}

Bank createAccount(char name[], int accountNumber, int balance)
{
    Bank b;
    strcpy(b.name, name);
    b.accountNumber = accountNumber;
    b.balance = balance; 
    return b;
}

void transfer(Bank *acc1, Bank *acc2)
{
    acc2 -> balance += acc1 -> balance;
    acc1 -> balance = 0; 
}

void printAllAccounts(Bank account[], int totalAcc)
{
    for(int i = 0; i < totalAcc; i++)
    {
        printAccount(account[i]);
    }
}
