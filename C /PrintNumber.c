// programma per stampare i num da 1  a 20 utilizzando il while 5 per riga
#include <stdio.h>

int main()
{
    int count = 1;
    int base = 5;

    while (count <= 20)
    {
        printf("%d ", count);
        if (count % 5 == 0) // controlla se la divisione del count per 5 ha resto 0 --> controlla se è un multiplo di 5
        {
            printf("\n");
        }

        count++;
    }
    return 0;
}