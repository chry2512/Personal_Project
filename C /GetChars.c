#include <stdio.h>

// print program to get a character from the user and print it

int main()
{
    int cr;

    printf("Enter a character, EOF to end:\n ");

    while ((cr = getchar()) != EOF)
    {
        if (cr != '\n')
        {
            printf("Char +1 is: %c \n", cr + 1);
            printf("Enter a character, EOF to end:\n ");
        }
    }

    return 0;
}