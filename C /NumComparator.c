#include <stdio.h>

int main() {
    int numero1, numero2;

    printf("Inserisci il primo numero: ");
    scanf("%d", &numero1);

    printf("Inserisci il secondo numero: ");
    scanf("%d", &numero2);

    int confronto = (numero1 < numero2) ? numero1 : numero2;

    printf("Il numero minore è: %d\n", confronto);

    return 0;
}