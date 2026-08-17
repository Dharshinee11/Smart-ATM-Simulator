#include <stdio.h>
#include "cash.h"

int notes500 = 20;
int notes200 = 20;
int notes100 = 30;

int validateCashAvailability(float amount)
{
    int required = (int)amount;
    int temp;
    int use500;
    int use200;
    int use100;

    if (required % 100 != 0)
    {
        return 0;
    }

    temp = required;

    use500 = temp / 500;

    if (use500 > notes500)
    {
        use500 = notes500;
    }

    temp = temp - (use500 * 500);

    use200 = temp / 200;

    if (use200 > notes200)
    {
        use200 = notes200;
    }

    temp = temp - (use200 * 200);

    use100 = temp / 100;

    if (use100 > notes100)
    {
        use100 = notes100;
    }

    temp = temp - (use100 * 100);

    if (temp != 0)
    {
        return 0;
    }

    return 1;
}

void dispenseCash(float amount)
{
    int required = (int)amount;
    int use500;
    int use200;
    int use100;

    use500 = required / 500;

    if (use500 > notes500)
    {
        use500 = notes500;
    }

    required = required - (use500 * 500);

    use200 = required / 200;

    if (use200 > notes200)
    {
        use200 = notes200;
    }

    required = required - (use200 * 200);

    use100 = required / 100;

    if (use100 > notes100)
    {
        use100 = notes100;
    }

    notes500 = notes500 - use500;
    notes200 = notes200 - use200;
    notes100 = notes100 - use100;

    printf("\n----------- CASH DISPENSED -----------\n");
    printf("Rs.500 notes : %d\n", use500);
    printf("Rs.200 notes : %d\n", use200);
    printf("Rs.100 notes : %d\n", use100);
    printf("--------------------------------------\n");
}