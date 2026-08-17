#include <stdio.h>
#include "transaction.h"

#define MAX_TRANSACTIONS 50

char transactionType[MAX_TRANSACTIONS][20];
float transactionAmount[MAX_TRANSACTIONS];

int transactionCount = 0;

void recordTransaction(char type[], float amount)
{
    if (transactionCount >= MAX_TRANSACTIONS)
    {
        printf("Transaction history is full.\n");
        return;
    }

    int i = 0;

    while (type[i] != '\0')
    {
        transactionType[transactionCount][i] = type[i];
        i++;
    }

    transactionType[transactionCount][i] = '\0';

    transactionAmount[transactionCount] = amount;

    transactionCount++;
}

void displayTransactions()
{
    int i;

    printf("\n================================\n");
    printf("       TRANSACTION HISTORY\n");
    printf("================================\n");

    if (transactionCount == 0)
    {
        printf("No transactions available.\n");
        return;
    }

    for (i = 0; i < transactionCount; i++)
    {
        printf("%d. %-12s Rs. %.2f\n",
               i + 1,
               transactionType[i],
               transactionAmount[i]);
    }

    printf("================================\n");
}