#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GOODS 10
#define MAX_NAME_LENGTH 50

typedef struct
{
    char name[MAX_NAME_LENGTH];
    float rate;
    int quantity;
    float price;
} Item;

void calculatePrice(Item *item)
{
    item->price = item->rate * item->quantity;
}

void printBillHeader()
{
    printf("\n");
    printf("********************************************\n");
    printf("          GROCERY BILLING SYSTEM\n");
    printf("********************************************\n");
}

void printBillFooter(float total)
{
    printf("********************************************\n");
    printf("          TOTAL: %.2f\n", total);
    printf("********************************************\n");
}

void printBill(Item *items, int itemCount)
{
    printf("\n");
    printf("%-20s | %-10s | %-10s | %-10s\n", "Item", "Rate", "Quantity", "Price");
    printf("--------------------------------------------\n");

    float total = 0;
    for (int i = 0; i < itemCount; i++)
    {
        printf("%-20s | %-10.2f | %-10d | %-10.2f\n", items[i].name, items[i].rate, items[i].quantity, items[i].price);
        total += items[i].price;
    }

    printf("--------------------------------------------\n");
    printBillFooter(total);
}

int main()
{
    int itemCount;
    printf("Enter the number of items: ");
    scanf("%d", &itemCount);

    if (itemCount <= 0 || itemCount > MAX_GOODS)
    {
        printf("Invalid number of items.\n");
        return 1;
    }

    Item items[MAX_GOODS];
    for (int i = 0; i < itemCount; i++)
    {
        printf("Enter the name of item %d: ", i + 1);
        scanf("%s", items[i].name);

        printf("Enter the rate of item %d: ", i + 1);
        scanf("%f", &items[i].rate);

        printf("Enter the quantity of item %d: ", i + 1);
        scanf("%d", &items[i].quantity);

        calculatePrice(&items[i]);
    }

    char customerName[MAX_NAME_LENGTH];
    printf("Enter customer name: ");
    scanf("%s", customerName);

    printBillHeader();
    printf("Customer: %s\n", customerName);
    printBill(items, itemCount);

    return 0;
}