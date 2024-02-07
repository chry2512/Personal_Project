#include <stdio.h>

void funct1(int a);
void funct2(int b);
void funct3(int c);

int main(void)
{
    // inizializza array di  3 puntatori a funzione
    //  ricevono come argomento un intero e non restituiscono nulla
    void (*f[3])(int) = {funct1, funct2, funct3};

    puts("Enter a number between 0 and 2, 3 to end");

    size_t choice; // scelta dell'utente
    scanf("%u", &choice);

    while (choice >= 0 && choice < 3)
    {
        // invoca la funzione alla posizione scelta dall'utente nell'array f e passa choise come argomento
        (*f[choice])(choice);

        puts("Enter a number between 0 and 2, 3 to end");
        scanf("%u", &choice);
    }

    puts("Program execution completed.");
}

void funct1(int a)
{
    printf("You entered %d so funct1 was called\n\n", a);
}

void funct2(int b)
{
    printf("You entered %d so funct2 was called\n\n", b);
}

void funct3(int c)
{
    printf("You entered %d so funct3 was called\n\n", c);
}