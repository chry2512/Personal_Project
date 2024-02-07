#include <stdio.h>
#include <string.h>

int main() {
    char stringa1[100], stringa2[100];

    printf("Inserisci la prima stringa: ");
    scanf("%s", stringa1);

    printf("Inserisci la seconda stringa: ");
    scanf("%s", stringa2);

    int confronto = (strcmp(stringa1, stringa2) == 0);// funzione della libreria string.h per fare il confronto tra due stringhe

    printf("Le due stringhe sono uguali: %d\n", confronto);

    return 0;
}