#include <stdio.h>
#define SIZE 10

size_t getSize(float *ptr);

int main(void)
{
    float array[SIZE];

    printf("The number of bytes in the array is: \n ");
    printf("%lu\n", sizeof(array));
    printf("The number of bytes returned by getSize is: \n");
    printf("%lu\n", getSize(array));
}

size_t getSize(float *ptr)
{
    return sizeof(ptr);
}