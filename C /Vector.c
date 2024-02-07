#include <stdio.h>

#define SIZE 5

int main()
{
    int vector[SIZE] = {1, 2, 3, 4, 5};
    int i;

    printf("Original vector: ");
    for (i = 0; i < SIZE; i++)
    {
        printf("%d ", vector[i]);
    }

    printf("\n");

    // Doubling each element of the vector
    for (i = 0; i < SIZE; i++)
    {
        vector[i] *= 2;
    }

    printf("Modified vector: ");
    for (i = 0; i < SIZE; i++)
    {
        printf("%d ", vector[i]);
    }

    printf("\n");

    return 0;
}
