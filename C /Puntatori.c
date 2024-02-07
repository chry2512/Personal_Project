#include <stdio.h>

void cubeByRefarance(int *nPtr);

int main(void)
{
    int number = 5;
    printf("The original value of number is %d\n", number);
    cubeByRefarance(&number);
    printf("The new value of number is %d\n", number);
}

void cubeByRefarance(int *nPtr)
{
    *nPtr = *nPtr * *nPtr * *nPtr;
}