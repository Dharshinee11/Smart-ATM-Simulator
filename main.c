#include <stdio.h>

#include "atm.h"
#include "security.h"
#include "transaction.h"
#include "cash.h"
#include "analytics.h"

int main()
{
    int choice;
    float amount;

    if (!authenticateUser())
    {
        return 0;
    }

    while (1)
    {
        printf("\n========================================\n");
        printf("             SMART ATM MENU\n");
        printf("========================================\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Transaction History\n");
        printf("5. Spending Analytics\n");
        printf("6. Account Insights\n");
        printf("7. Change PIN\n");
        printf("8. ATM Cash Status\n");
        printf("9. Exit\n");
        printf("========================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                checkBalance();
                break;

            case 2:
                depositMoney();
                break;

            case 3:
                printf("\nEnter withdrawal amount: Rs.");
                scanf("%f", &amount);

                if (amount > balance)
                {
                    printf("Insufficient balance.\n");
                }
                else if (!validateCashAvailability(amount))
                {
                    printf("ATM cannot dispense this amount.\n");
                    printf("Amount must match available denominations.\n");
                }
                else
                {
                    withdrawMoney();
                    dispenseCash(amount);

                    recordTransaction("WITHDRAWAL", amount);
                }
                break;

            case 4:
                displayTransactions();
                break;

            case 5:
                showSpendingAnalytics();
                break;

            case 6:
                showAccountInsights();
                break;

            case 7:
                changePIN();
                break;

            case 8:
                printf("\n========================================\n");
                printf("           ATM CASH STATUS\n");
                printf("========================================\n");
                printf("Cash management module active.\n");
                printf("Available denominations: Rs.500, Rs.200, Rs.100\n");
                break;

            case 9:
                printf("\nThank you for using Smart ATM.\n");
                printf("Session terminated securely.\n");
                return 0;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}