// programm to calculate the moltiplication table of a number
#include <stdio.h>

int main(void)
{
    unsigned int num;
    int count = 1;

    printf("Enter a number: \n");
    scanf("%u", &num);

    printf("<<<<Moltiplication table of: %u\n", num);

    while (count <= 10)
    {
        printf("%u * %u = %u\n", num, count, num * count);
        count++;
    }

    return 0;
}
