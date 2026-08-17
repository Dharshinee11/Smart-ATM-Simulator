#include <stdio.h>
#include "analytics.h"
#include "atm.h"

void showSpendingAnalytics()
{
    printf("\n================================\n");
    printf("        SPENDING ANALYTICS\n");
    printf("================================\n");

    printf("Current Balance : Rs. %.2f\n", balance);

    if (balance < 500)
    {
        printf("Status : LOW BALANCE\n");
    }
    else if (balance < 2000)
    {
        printf("Status : MODERATE BALANCE\n");
    }
    else
    {
        printf("Status : HEALTHY BALANCE\n");
    }
}

void showAccountInsights()
{
    printf("\n================================\n");
    printf("         ACCOUNT INSIGHTS\n");
    printf("================================\n");

    if (balance < 500)
    {
        printf("Alert : Balance is critically low.\n");
        printf("Suggestion : Consider making a deposit.\n");
    }
    else if (balance < 2000)
    {
        printf("Alert : Balance is getting low.\n");
        printf("Suggestion : Monitor your withdrawals.\n");
    }
    else
    {
        printf("Account condition : Stable.\n");
    }
}