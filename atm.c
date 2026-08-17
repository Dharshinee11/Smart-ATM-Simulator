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

    /* Load previously saved account data */
    loadAccount();

    /* Secure login */
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
            /* =========================
               CHECK BALANCE
               ========================= */
            case 1:
                checkBalance();
                break;


            /* =========================
               DEPOSIT
               ========================= */
            case 2:
                depositMoney();
                break;


            /* =========================
               WITHDRAWAL
               ========================= */
            case 3:
                printf("\nEnter withdrawal amount: Rs.");
                scanf("%f", &amount);

                if (amount <= 0)
                {
                    printf("\nInvalid withdrawal amount.\n");
                }
                else if (amount > balance)
                {
                    printf("\n========================================\n");
                    printf("       TRANSACTION DECLINED\n");
                    printf("========================================\n");
                    printf("Reason: Insufficient balance.\n");
                    printf("Available Balance: Rs. %.2f\n", balance);
                }
                else if ((int)amount % 100 != 0)
                {
                    printf("\nATM ERROR\n");
                    printf("Amount must be a multiple of Rs.100.\n");
                }
                else if (!validateCashAvailability(amount))
                {
                    printf("\n========================================\n");
                    printf("       TRANSACTION DECLINED\n");
                    printf("========================================\n");
                    printf("ATM cannot dispense the requested amount\n");
                    printf("using currently available denominations.\n");
                }
                else
                {
                    /*
                       withdrawMoney() asks for the amount again
                       in the current atm.c.
                       Therefore we call it after validation.
                    */
                    withdrawMoney();

                    /*
                       Dispense physical ATM cash
                    */
                    dispenseCash(amount);
                }

                break;


            /* =========================
               TRANSACTION HISTORY
               ========================= */
            case 4:
                displayTransactions();
                break;


            /* =========================
               SPENDING ANALYTICS
               ========================= */
            case 5:
                showSpendingAnalytics();
                break;


            /* =========================
               ACCOUNT INSIGHTS
               ========================= */
            case 6:
                showAccountInsights();
                break;


            /* =========================
               CHANGE PIN
               ========================= */
            case 7:
                changePIN();
                break;


            /* =========================
               ATM CASH STATUS
               ========================= */
            case 8:
                printf("\n========================================\n");
                printf("           ATM CASH STATUS\n");
                printf("========================================\n");

                printf("Available denominations:\n");
                printf("Rs.500\n");
                printf("Rs.200\n");
                printf("Rs.100\n");

                printf("\nATM Cash Management Module: ACTIVE\n");
                printf("ATM Status: ONLINE\n");

                break;


            /* =========================
               EXIT
               ========================= */
            case 9:

                /*
                   Save balance before exiting
                */
                saveAccount();

                printf("\n========================================\n");
                printf("        ACCOUNT DATA SAVED\n");
                printf("========================================\n");

                printf("Thank you for using Smart ATM.\n");
                printf("Session terminated securely.\n");

                return 0;


            /* =========================
               INVALID OPTION
               ========================= */
            default:
                printf("\n========================================\n");
                printf("          INVALID CHOICE\n");
                printf("========================================\n");
                printf("Please select an option from 1 to 9.\n");
        }
    }

    return 0;
}