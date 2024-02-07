#include <stdio.h>
// media voti iterazione con sentinella --> iterazione indefinita
int main(void)
{
    // dichiarazione variabili
    unsigned int count; // contatore
    int grade;          // voto
    int total;          // somma voti
    int average;        // media voti

    // inizializzazione
    total = 0;
    count = 0;

    // elaborazione input
    // prompt per prendere il primo voto
    printf("%s", "Inserisci voto o -1 per terminare:  \n");
    scanf("%d", &grade); // leggi il voto

    while (grade != -1)
    {
        total = total + grade; // aggiungi grade a total
        count = count + 1;     // incrementa il contatore

        printf("%s", "Inserisci voto o -1 per terminare:  \n");
        scanf("%d", &grade); // leggi il voto
    }                        // fine iterazione

    if (count != 0) // warning gestione crashing se dividiamo per 0
    {
        average = total / count; // calcola la media
        printf("La media dei voti e': %d\n", average);
    }
    else
    {
        puts("Nessun voto inserito");
    }

    return 0; // fine main programma
}