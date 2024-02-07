#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *numbers;
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Dynamically allocate memory for the array
    numbers = (int *)malloc(size * sizeof(int));

    if (numbers == NULL)
    {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }

    printf("Enter %d numbers:\n", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &numbers[i]);
    }

    printf("You entered: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // Free the dynamically allocated memory
    free(numbers);

    return 0;
}
