#include <stdio.h>

// function che fa la somma di tutti i numeri dispari da 1 a 99
int sumOddNumbers(int n)
{
    int sum = 0;
    int count = 1;

    do
    {
        if (count % 2 != 0)
        {
            sum += count;
        }
        count++;
    } while (count <= n);

    return sum;
}

// funzione per calcolare la media di una sequenza di interi inseriti dall'utente
double average()
{

    int number = 0;
    int total = 0;
    int count = 0;
    printf("Enter a sequence of integers or 9999 to terminate: \n");

    while (number != 9999)
    {

        scanf("%d", &number);

        if (number == 9999)
        {
            break;
        }

        total += number;
        count++;
    }

    printf("The Average in function is: %.2f\n", (double)total / count);

    return total / count;
}

int main()
{

    int choise;
    int sum;
    double calculateAverage;

    printf("Choise Function: \n");
    printf("1. Sum Odd Numbers\n");
    printf("2. Average\n");
    scanf("%d", &choise);

    switch (choise)
    {
    case 1:
        // Print sum odd numbers
        sum = sumOddNumbers(99);
        printf("Sum Odd Numbers: %d\n", sum);
        break;

    case 2:
        // Print  average numbers
        calculateAverage = (double)average();
        printf("The Average is: %.2f\n", calculateAverage);
        break;

    default:
        break;
    }

    return 0;
}