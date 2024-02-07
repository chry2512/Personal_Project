#include <stdio.h>
#define SIZE 10

void bubble(int work[], size_t size, int (*compare)(int a, int b));
int ascending(int a, int b);
int descending(int a, int b);

int main(void)
{
    int a[SIZE] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37}; // inizializza array
    int order;                                          // 1 = ascending, 2 = descending
    int counter;                                        // contatore per inizializzare array

    printf("Enter 1 to sort in ascending order,\n"
           "Enter 2 to sort in descending order: ");
    scanf("%d", &order);

    puts("\nData items in original order");

    for (size_t counter = 0; counter < SIZE; counter++)
    {
        printf("%5d", a[counter]);
    }

    // imposta puntatore a funzione di ordinamento
    // in base all'ordine specificato dall'utente
    if (order == 1)
    {
        bubble(a, SIZE, ascending);
        puts("\nData items in ascending order");
    }
    else
    {
        bubble(a, SIZE, descending);
        puts("\nData items in descending order");
    }

    for (size_t counter = 0; counter < SIZE; counter++)
    {
        printf("%5d", a[counter]);
    }

    puts("\n");

    return 0;
}

void bubble(int work[], size_t size, int (*compare)(int a, int b))
{
    void swap(int *element1Ptr, int *element2Ptr); // prototipo

    // nel bubble sort i passagi del confronto seno sempre uno in meno rispetto alla dimesione dell'array

    // ciclo per controllare size-1 elementi
    for (unsigned int pass = 1; pass < size; pass++)
    {
        // ciclo per controllare elementi adiacenti
        for (size_t count = 0; count < size - 1; count++)
        {
            // se elemento successivo è minore, scambia i due elementi
            if ((*compare)(work[count], work[count + 1]))
            {
                swap(&work[count], &work[count + 1]);
            }
        }
    }
}

void swap(int *element1Ptr, int *element2Ptr)
{
    int hold = *element1Ptr;
    *element1Ptr = *element2Ptr;
    *element2Ptr = hold;
}

int ascending(int a, int b)
{
    return b < a; // scambia se b è minore di a
}

int descending(int a, int b)
{
    return b > a; // scambia se b è maggiore di a
}
