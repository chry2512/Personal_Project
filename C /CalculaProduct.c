
// Program: calculate product of two numbers
#include <stdio.h>

int main()
{
    unsigned int x = 0;
    unsigned int y = 0;
    unsigned int product;
    int i; // valore sentinella

    while (i != 1)
    {
        printf("Enter First Number(x): \n"); // print message
        scanf("%u", &x);                     // scan num insert user

        printf("Enter  Second Number(y): \n"); // print message
        scanf("%u", &y);                       // scan number insert user

        product = x * y;
        printf("<<<<Product value is: %u\n", product);

        if (x == 0 || y == 0)
        {
            printf("<<<<Product value is: %u\n", product = 0);
        }

        printf("<<<<Do you want to continue?(y/n) :  \n");
        printf("0. y:  \n");
        printf("1. n:  \n");
        scanf("%d", &i);

        if (i == 1)
        {
            printf("<<<<Bye Bye\n");
        }
    }

    return 0;
}