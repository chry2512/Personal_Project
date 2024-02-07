#include <stdio.h>

void ordina(int arr[], int n);

int main()
{

    printf("<<<<<<<<<Elaborato Esercizio2\n");

    puts("<<<<<<<<Welcome<<<<<<<<<<");
    puts("<<<<<<<<Inserisci tre numeri: ");

    int numeri[3];
    int i;

    for (i = 0; i < 3; i++)
    {
        printf("<<<<<<<<<<<<<Inserisci il numero %d:\n", i + 1);
        scanf("%d", &numeri[i]);
    }

    ordina(numeri, 3);

    if (numeri[0] == numeri[1] && numeri[1] == numeri[2])
    {
        printf("<<<<<<<<<<<<I numeri sono uguali");
    }
    else
    {

        puts("<<<<<<<<<<<<<<<<I numeri stampati in ordine decrescente sono: ");
        printf("%d %d %d", numeri[0], numeri[1], numeri[2]);
    }

    return 0;
}

void ordina(int arr[], int n)
{
    int i, j, temp;

    // bubble sort algorithm
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}