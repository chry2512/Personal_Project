#include <stdio.h>

#define A_SIZE 4

int main()
{
    int b[] = {10, 20, 30, 40}; // inizializza array

    int *bPtr = b; // imposta bPtr a puntare all'elemento 0 di b

    puts("Array b printed with:");
    puts("Array index notation"); // notazione indice di array

    for (size_t i = 0; i < A_SIZE; i++)
    {
        printf("b[%lu] = %d\n", i, b[i]); // stampa con notazione array indice
    }
    puts("\nPointer/offset notation witrh array name");
    for (size_t offset = 0; offset < A_SIZE; offset++)
    {
        printf("*(b + %lu) = %d\n", offset, *(b + offset)); // stampa con notazione puntatore/offset utilizzando nome array
    }

    puts("\nPointer subscript notation");

    for (size_t i = 0; i < A_SIZE; i++)
    {
        printf("bPtr[%lu] = %d\n", i, bPtr[i]); // stampa con notazione puntatore/indice
    }

    puts("\nPointer/offset notation con puntatore");
    for (size_t i = 0; i < A_SIZE; i++)
    {
        printf("*(bPtr + %lu) = %d\n", i, *(bPtr + i)); // stampa con notazione puntatore/offset utilizzando nome puntatore
    }

    return 0;
}