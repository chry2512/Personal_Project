// programma che calcola  x elevato alla potenza di y, dati due numeri interi x e y inseriti dall'utente.

#include <stdio.h>

int main()
{
    unsigned int x = 0;
    unsigned int y = 0;
    unsigned int power = 1;
    int i = 1;

    printf("Enter First Number(x): \n"); // print message
    scanf("%u", &x);                     // scan num insert user

    printf("Enter  Second Number(y): \n"); // print message
    scanf("%u", &y);                       // scan number insert user

    while (i <= y)
    {
        power *= x;
        ++i;
    }

    printf("<<<<Elevate value is: %u\n", power);

    return 0;
}