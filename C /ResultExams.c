#include <stdio.h>

int main(void)
{

    // inizializazione variabili

    unsigned int passes = 0;
    unsigned int failures = 0;
    unsigned int student = 1;
    int result; // result esame

    while (student <= 10)
    {
        // inserire il risultato (1 = pass, 2 = fail);
        printf("%s", "Enter result Exam, (insert 1 = pass or 2 = fail : \n");
        scanf("%d", &result);
        if (result == 1)
        {
            passes++;
        }
        else if (result == 2)
        {
            failures++;
        }
        else
        {
            printf("%s", "Insert a valid number (1 or 2) \n");
            continue;
        }

        student++;
    }

    printf("<<<<<<<<Passed %u\n", passes);
    printf("<<<<<<<<Failed %u\n", failures);

    if (passes > 8)
    {
        printf("%s", "<<<<<<<<<<Bonus to instructor \n");
    }
    else
    {
        printf("%s", "<<<<<<<<<No bonus to instructor \n");
    }

    return 0;
}