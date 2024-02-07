#include <stdio.h>
#define SIZE 80

int palindromo(char arrayChars[SIZE], int left, int right);

int main()
{

    char string[SIZE];
    char copyString[SIZE];

    char c;
    unsigned int count = 0;

    puts("Enter a string: ");

    while ((c = getchar()) != '\n' && count < SIZE)
    {
        string[count++] = c;
    }

    string[count] = '\0';

    unsigned int copyCount = 0;

    for (unsigned int i = 0; string[i] != '\0'; ++i)
    {
        if (string[i] != ' ' && string[i] != '.' && string[i] != ',' && string[i] != '!' && string[i] != '?')
        {
            copyString[copyCount++] = string[i];
        }
    }

    if (palindromo(copyString, 0, copyCount - 1) == 1)
    {
        puts("The string is a palindrome");
    }
    else
    {
        puts("The string is not a palindrome");
    }

    return 0;
}

int palindromo(char arrayChars[SIZE], int left, int right)
{
    if (left >= right)
    {
        return 1;
    }
    else if (arrayChars[left] != arrayChars[right])
    {
        return 0;
    }
    else
    {
        return palindromo(arrayChars, left + 1, right - 1);
    }
}