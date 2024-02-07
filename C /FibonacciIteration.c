#include <stdio.h>
#define MAX 93

unsigned long long int fibonacci(unsigned int n);

int main(void)
{
    for (unsigned int i = 0; i <= MAX; i++)
    {
        printf("Fibonacci(%u) = %llu\n", i, fibonacci(i));
    }
    return 0;
}

unsigned long long int fibonacci(unsigned int n)
{
    unsigned long long int fib1 = 0;
    unsigned long long int fib2 = 1;

    for (unsigned int j = 2; j <= n; j++)
    {
        if (j % 2)
        {

            fib2 += fib1;
        }
        else
        {

            fib1 += fib2;
        }
    }

    if (n % 2)
    {
        return fib2;
    }
    else
    {

        return fib1;
    }
}
