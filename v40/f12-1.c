#include <stdio.h>
#include <string.h>


struct bank;
{
    char name[30];
    int money;
} user1, user2;

char createAccount(char name[30],int money);
char printAccount(char name[30],int money,int temp , int total);
int transfer(int money);
int main()
{
    struct bank;;
    char name[30];
    int money;
    int temp;
    int total;
    createAccount(name,money);
    printAccount(name, money, temp, total);
    return 0;
}

char createAccount(char name[30],int money){

    strcpy(user1.name,"Simran Singh");
    user1.money = 3210;

    strcpy(user2.name,"Mark Asplund");
    user2.money = 210;

}

char printAccount(char name[30],int money, int temp , int total)
{
    printf("%s - %d kr\n", user1.name, user1.money);
    printf("%s - %d kr\n", user2.name, user2.money);
    transfer(money);
    printf("%s - %d kr\n",user1.name, user2.money);
    printf("%s - %d kr\n",user2.name, user1.money);
}

int transfer(int money)
{
int temp;
int total;

total = user1.money + user2.money;
user1.money = total;
temp = user2.money - user2.money;
user2.money = temp;
}