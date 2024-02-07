#include <stdio.h>
#include <limits.h>

int main()
{
    int n; // n = numero inserito dall'utente,
    int i; // i = contatore
    int end;
    int fact = 1;

    printf("Enter a number to start calculate its factorial\n");
    scanf("%d", &n);

    printf("Enter a number to finish calculate its factorial\n");
    scanf("%d", &end);

    if (n == end)
    {
        fact = 1;
        for (i = 1; i <= n; i++)
        {
            fact = fact * i;
        }

        if (n != 9)
        {
            printf("Factorial of %d = %d\n", n, fact);
        }
        else
        {
            printf("Factorial of 9 it's not possible to calculate\n");
        }
    }
    else
    {
        for (int j = n; j <= end; j++)
        {
            fact = 1;
            for (i = 1; i <= j; i++)
            {
                // condizione per controllare se fact e maggiore dei limiti di int utilizzando la libreria limit.h
                if (fact > INT_MAX / i)
                {
                    printf("Warnig !! Factorial of %d it's not possible to calculate\n", j);
                    break;
                }

                fact = fact * i;
            }
            if (j == 9)
            {
                printf("Warnig !! Factorial of 9 it's not possible to calculate\n");
                continue;
            }
            else
            {
                printf("Factorial of %d = %d\n", j, fact);
            }
        }
    }

    return 0;
}