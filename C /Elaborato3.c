#include <stdio.h>

int main()
{
    // Scrivere un programma che calcola i primi N numeri di Fibonacci, con N introdotto da tastiera
    printf("<<<<<<<<<Elaborato Esercizio3\n");

    int n, i;
    int nextNumFibonacci;
    int t1 = 1, t2 = 1;
    puts("<<<<<<<<Welcome<<<<<<<<<<");
    printf("Quanti N numeri di Fibonacci vuoi calcolare?: \n");
    scanf("%d", &n);
    printf("Fibonacci Series: ");
    for (i = 1; i <= n; ++i)
    {
        printf("%d, ", t1);
        nextNumFibonacci = t1 + t2;
        t1 = t2;
        t2 = nextNumFibonacci;
    }
    return 0;
}