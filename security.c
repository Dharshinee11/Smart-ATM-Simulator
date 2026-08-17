#include <stdio.h>
#include "security.h"

int storedPIN = 1234;

/* ================================
   USER AUTHENTICATION
   ================================ */

int authenticateUser()
{
    int pin;
    int attempts = 0;
    int maxAttempts = 3;

    printf("\n========================================\n");
    printf("          SECURE ATM LOGIN\n");
    printf("========================================\n");

    while (attempts < maxAttempts)
    {
        printf("\nEnter PIN: ");
        scanf("%d", &pin);

        if (pin == storedPIN)
        {
            printf("\n========================================\n");
            printf("        LOGIN SUCCESSFUL\n");
            printf("        Welcome to Smart ATM\n");
            printf("========================================\n");

            return 1;
        }

        attempts++;

        printf("\n[SECURITY WARNING]\n");
        printf("Incorrect PIN!\n");

        if (attempts < maxAttempts)
        {
            printf("Attempts remaining: %d\n",
                   maxAttempts - attempts);
        }
    }

    printf("\n========================================\n");
    printf("          ACCOUNT LOCKED\n");
    printf("========================================\n");
    printf("Reason : Too many incorrect PIN attempts\n");
    printf("Action : ATM session terminated\n");
    printf("Status : SECURITY LOCK ACTIVE\n");
    printf("========================================\n");

    return 0;
}


/* ================================
   CHANGE PIN
   ================================ */

int changePIN()
{
    int oldPIN;
    int newPIN;

    printf("\n========================================\n");
    printf("             PIN CHANGE\n");
    printf("========================================\n");

    printf("\nEnter current PIN: ");
    scanf("%d", &oldPIN);

    /* Verify current PIN */
    if (oldPIN != storedPIN)
    {
        printf("\n[SECURITY ALERT]\n");
        printf("Incorrect current PIN.\n");
        printf("PIN change cancelled for security.\n");

        return 0;
    }

    printf("Enter new PIN: ");
    scanf("%d", &newPIN);

    /* Check 4 digit PIN */
    if (newPIN < 1000 || newPIN > 9999)
    {
        printf("\nInvalid PIN!\n");
        printf("PIN must contain exactly 4 digits.\n");

        return 0;
    }

    /* Prevent same PIN */
    if (newPIN == storedPIN)
    {
        printf("\nPIN CHANGE REJECTED!\n");
        printf("New PIN cannot be the same as old PIN.\n");

        return 0;
    }

    storedPIN = newPIN;

    printf("\n========================================\n");
    printf("        PIN CHANGED SUCCESSFULLY\n");
    printf("========================================\n");
    printf("Your new PIN is now active.\n");
    printf("Security status : UPDATED\n");

    return 1;
}