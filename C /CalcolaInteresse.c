#include <stdio.h>
#include <math.h>

// function to calculate interest + capital

int main()
{
    double capital = 1000.0;
    float interest = 0.05;
    double amount = 0.0;
    int total;

    for (unsigned int year = 1; year <= 10; ++year)
    {
        amount = capital * pow(1.0 + interest, year);
        printf("Capital after %u years: %.2f\n", year, amount);
    }

    for (int i = 44, count = 11; i >= 0; i -= count++)
    {
        printf("The number is: %d\n", i);
    }

    for (int i = 2; i <= 100; i += 2)
    {
        total += i;
        printf("The number even is: %d\n", i);
    }

    printf("The sum is: %d\n", total);

    return 0;
}
