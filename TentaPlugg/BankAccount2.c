#include <stdio.h>
#include <string.h>
#define LASTNAME 15

struct bankAccount{
    char name[LASTNAME];
    int accountNr, balance;
}; typedef struct bankAccount Bank;

void printAccount(Bank b);
Bank createAccount(char name[], int accountNr, int balance);
void transfer(Bank *acc1, Bank *acc2);
void printAll(Bank accounts[], int nrOfAccs);


int main(void)
{
    Bank account1 = {"Shevek", 123, 230};
    printAccount(account1);
    Bank account2 = createAccount("Ketho", 124, 300);
    printAccount(account2);
    transfer(&account1, &account2);
    printAccount(account1);
    printAccount(account2);

    Bank accounts[2] = {account1, account2};
    int nrOfAccs = 2;
    printf("\n");

    printAll(accounts, nrOfAccs);
}

void printAccount(Bank b)
{
    printf("%s, %d, %dkr\n", b.name, b.accountNr, b.balance);
}

Bank createAccount(char name[], int accountNr, int balance)
{
    Bank b;
    strcpy(b.name, name);
    b.accountNr = accountNr;
    b.balance = balance;
    return b;
}

void transfer(Bank *acc1, Bank *acc2)
{   
    acc2 -> balance += acc1 -> balance;
    acc1 -> balance = 0;
}

void printAll(Bank accounts[], int nrOfAccs)
{
    for(int i = 0; i < nrOfAccs; i++)
    {
        printAccount(accounts[i]);
    }
}