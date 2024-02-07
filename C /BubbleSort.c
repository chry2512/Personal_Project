#include <stdio.h>
#define SIZE 10

int arrayMulti(int a[SIZE][SIZE]);

int main()
{
    int a[SIZE] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};
    puts("Data items in original order");

    for (size_t i = 0; i < SIZE; ++i)
    {
        printf("%4d", a[i]);
    }

    // nel bubble sort i passagi del confronto seno sempre uno in meno rispetto alla dimesione dell'array

    for (unsigned int pass = 1; pass < SIZE; ++pass)
    {
        for (size_t i = 0; i < SIZE - 1; ++i)
        {
            if (a[i] > a[i + 1])
            {
                int hold = a[i];
                a[i] = a[i + 1];
                a[i + 1] = hold;
            }
        }
    }

    puts("\nData items in ascending order");

    for (size_t i = 0; i < SIZE; ++i)
    {
        printf("%4d", a[i]);
    }

    puts("");

    int b[SIZE][SIZE] = {{1, 2, 3}, {3, 2, 1}};

    int result = arrayMulti(b);

    if (result == 0)
    {
        puts("Success");
    }
    else
    {
        puts("Error");
    }
}

int arrayMulti(int a[SIZE][SIZE])
{

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            a[i][j] = i + j;

            printf("Element is: %d ", a[i][j]);
        }
    }

    return 0;
}