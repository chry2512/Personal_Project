#include <stdio.h>

int main()
{

    // ENUM --> insieme di costanti, IL SUO VALORE PARTE DA 0 A SALIRE
    enum giorni {lunedi, martedi, mercoledi, giovedi, venerdi, sabato, domenica};

    // interi
    int num = 5;
    num = 10;

    // numeri in virgola mobile
    float pi = 3.14;  
    pi = 3.1415;
    
    // caratteri

    char lettera = 'a';

    // stringhe
    char nome[] = "Mario";

    // booleani
    int vero = 1;
    int falso = 0;

    //inserimento da tastiera
    int input;

    printf("Inserisci un numero: ");
    scanf("&d", &input);

    // operazioni   
    int x = 5;
    int y = 10;

    int somma = x + y;


    // cast


    float a = 5.5;

    int b = (int) a;// operazione di cast per troncamento


    // swap --> memorizza valore in una variabile temporanea

    int temp = x;
    x = y;
    y = temp;


    // array interi,

    int numeri[5] = {1, 2, 3, 4, 5};

    // dichiarazione di una costante
    const int COSTANTE = 5;

    //puntatori

    int *puntatore = &x;

    // dichiarare una struttura

    struct studente
    {
        char nome[50];
        int eta;
        float media;
    };




    return 0;
}