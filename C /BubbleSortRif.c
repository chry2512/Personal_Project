#include <stdio.h>
#define SIZE 10

// prototipo
void bubbleSort(int *const array, const size_t size);

int main(void)
{
    int a[SIZE] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};
    puts("Data items in original order");

    for (size_t i = 0; i < SIZE; ++i)
    {
        printf("%4d", a[i]);
    }

    bubbleSort(a, SIZE);

    puts("\nData items in ascending order");

    for (size_t i = 0; i < SIZE; ++i)
    {
        printf("%4d", a[i]);
    }

    puts("");

    return 0;
}

void bubbleSort(int *const array, const size_t size)
{
    // prototipo interno alla funzione
    void swap(int *element1Ptr, int *element2Ptr);

    // se pass inizializzato a 0 occorre usare < size - 1
    // per maggiore comodità inizializzare pass a 1
    // nel bubble sort i passagi del confronto seno sempre uno in meno rispetto alla dimesione dell'array

    for (unsigned int pass = 0; pass < size - 1; ++pass)
    {
        for (size_t j = 0; j < size - 1; ++j)
        {
            if (array[j] > array[j + 1])
            {
                swap(&array[j], &array[j + 1]);
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