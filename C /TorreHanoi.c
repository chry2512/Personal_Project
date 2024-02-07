#include <stdio.h>

void hanoi(int numeroDischi, char pioloIniziale, char pioloFinale, char pioloDiAppoggio);

int main(void)
{
    int numeroDischi;
    char pioloIniziale;
    char pioloFinale;
    char pioloDiAppoggio;

    printf("Welcome to the Game of Hanoi\n");
    printf("Inserisci il numero di dischi: ");
    scanf("%d", &numeroDischi);

    printf("Inserisci il piolo iniziale: ");
    scanf("%c", &pioloIniziale);

    printf("Inserisci il piolo finale: ");
    scanf("%c", &pioloFinale);

    printf("Inserisci il piolo di appoggio: ");
    scanf("%c", &pioloDiAppoggio);

    hanoi(numeroDischi, pioloIniziale, pioloFinale, pioloDiAppoggio);

    return;
}

void hanoi(int numeroDischi, char pioloIniziale, char pioloDiAppoggio, char pioloFinale)
{

    if (numeroDischi == 1)
    {
        printf("Sposta il disco %d dal piolo %c al piolo %c\n", numeroDischi, pioloIniziale, pioloFinale);
        return 0;
    }
    else
    {
        hanoi(numeroDischi - 1, pioloIniziale, pioloDiAppoggio, pioloFinale);
        printf("Sposta il disco %d dal piolo %c al piolo %c\n", numeroDischi, pioloIniziale, pioloFinale);
        hanoi(numeroDischi - 1, pioloIniziale, pioloDiAppoggio, pioloFinale);
    }
}