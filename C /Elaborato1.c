#include <stdio.h>
#include <math.h>

double calcolaMedia(long int matricola, int cifre);
int contaCifre(long int matricola);

int main()
{

    long int matricola;
    double media;
    int cifre;

    printf("<<<<<<<<<Elaborato Esercizio1\n");

    puts("Welcome");
    puts("Inserisci la tua matricola");

    scanf("%ld", &matricola);

    cifre = contaCifre(matricola);

    printf("la tua matricola e' composta da %d cifre\n", cifre);
    // controllo se la matricola è composta da 9 cifre come da traccia
    if (cifre != 9)
    {
        puts("Matricola non valida ! Deve essere di 9 Cifre !");
        return 1; // 1 = terminate program with error in C
    }

    /** Alternativa per verificare se la matricola è valida con multipli di 9
    * Version con matricole più grandi di 9 cifre
    if (!(cifre % 9 == 0))
    {
        puts("Matricola non valida ! Deve essere un multiplo di 9 !");
        return 1; // 1 = terminate program with error in C
    }
    **/

    media = calcolaMedia(matricola, cifre);
    printf("Questa è la media della mia matricola divisa in quattro gruppi: %.2f\n", media);
    printf("Bye Bye >>>>>>>>>");

    return 0; // 0 = success terminate program in C
}

double calcolaMedia(long int nMatricola, int nCifre)
{
    /**
     *  Diviamo la matricola per la potenza di 10 elevato a n - 3 per rimuovere n - 3 cifre
     *  cosi otteniamo le prime tre cifre
     *  il risultato sposterà verso destra la virgola di -> risultato = n - 3 posizioni
     **/

    long int a = nMatricola / (long int)pow(10, nCifre - 3);
    printf("Le prime tre cifre sono: %ld\n", a);

    /**
     *  Diviamo la matricola per la potenza di 10 elevato a n - 5 per rimuovere n-5 cifre
     *  cosi  otteniamo le prime 5 cifre
     *  il risultato sposterà verso destra la virgola di n posizioni
     *  utilizziamo l'operatore modulo per ottenere le ultime due cifre del numero risultante (posizione 4 e 5)
     **/

    long int b = (nMatricola / (long int)pow(10, nCifre - 5)) % 100;
    printf("Le successive due cifre sono: %ld\n", b);

    /**
     *  Diviamo la matricola per la potenza di 10 elevato a n - 7 per rimuovere n - 7 cifre
     *  otteniamo cosi le prime 7 cifre
     *  il risultato sposterà verso destra la virgola di n posizioni
     *  utilizziamo l'operatore modulo per ottenere le ultime due cifre del numero risultante (posizione 6 e 7)
     **/

    long int c = (nMatricola / (long int)pow(10, nCifre - 7)) % 100;
    printf("Le successive altre due cifre sono: %ld\n", c);

    /**
     * otteniamo le ultime due cifre  con l'operatore modulo
     * ovvero il resto della divisione tra la matricola e 100
     * spostando la virgola di due posizioni verso destra(le ultime due cifre della matricola)¢¢
     **/

    long int d = nMatricola % 100;
    printf("Le ultime due cifre sono: %ld\n", d);

    // calcolo della media divisa per 4 gruppi di cifre
    double media = (a + b + c + d) / 4;
    return media;
}
int contaCifre(long int nMatricola)
{
    int conteggio = 0;

    // sistema di notazione posizionale su base 10 per contare da quante cifre è composto la matricola
    while (nMatricola != 0)
    {
        nMatricola /= 10;
        conteggio++;
    }
    return conteggio;
}