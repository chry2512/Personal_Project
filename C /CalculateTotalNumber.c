#include <stdio.h>
#include <string.h>

int main(void)
{
    int num = 0;
    int sum = 0;
    int rest;
    char check[2];
    do
    {
        puts("<<<<<<<<<<Enter a number: ");
        scanf("%d", &num);
        sum += num;
        printf("<<<<<<<<<<<<Sum is: %d\n", sum);

        rest = sum % 2;

        if (rest == 0)
        {
            printf("<<<<<<<<The sum is even\n");
        }
        else
        {
            printf("<<<<<<<<The sum is odd\n");
        }

        printf("<<<<<<Do you want to continue? (y/n):  \n");
        scanf("%s", check);
    } while (*check == 'y');

    return 0;
}
