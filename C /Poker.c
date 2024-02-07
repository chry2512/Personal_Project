#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CARDS 52 // carte nel mazzo
#define HANDS 5  // carte per giocatore una mano
#define SUITS 4  // semi nel mazzo
#define FACES 13 // facce in una carta

void shuffle(unsigned int deck[][FACES]); // mischia carte

void deal(unsigned int deck[][FACES], unsigned int handCards[][2], const char *wFace[], const char *wSuit[]); // distribuisci carte

void pair(unsigned int handCards[][2], const char *wFace[], const char *wSuit[], int *points, int player); // coppia

void twoPair(unsigned int handCards[][2], const char *wFace[], const char *wSuit[], int *points, int player); // doppia coppia

void threeOfKind(unsigned int handCards[][2], const char *wFace[], const char *wSuit[], int *points, int player); // tris

void fourOfKind(unsigned int handCards[][2], const char *wFace[], const char *wSuit[], int *points, int player); // poker

void straight(unsigned int handCards[][2], const char *wFace[], const char *wSuit[], int *points, int player); // scala

void flush(unsigned int handCards[][2], const char *wFace[], const char *wSuit[], int *points, int player); // colore

void fullHouse(unsigned int handCards[][2], const char *wFace[], const char *wSuit[], int *points, int player); // full

void royalFlush(unsigned int handCards[][2], const char *wFace[], const char *wSuit[], int *points, int player); // scala reale

int main()
{
    int numberPlayer = 0; // numero giocatori

    puts("<<<<<<<<<<<<<Welkcome to Poker Game>>>>>>>>>>>>>>");
    puts("<<<<<<<<<<<<<How many players?>>>>>>>>>>>>>>>>>>>");

    scanf("%d", &numberPlayer);

    printf("<<<<<<<<<<<The Number of Player  is: %d \n", numberPlayer);

    int result[numberPlayer]; // risultato
    int *points = result;     // punteggio

    // inizializza a zero result
    for (int i = 0; i < numberPlayer; i++)
    {
        result[i] = 0;
    }

    int highestScore = result[0]; // punteggio più alto
    int winners[numberPlayer];    // vincitori
    int winnerCount = 0;          // contatore vinciitori

    unsigned int deck[SUITS][FACES] = {0};  // initialize deck array
    unsigned int handCards[HANDS][2] = {0}; // initialize handCards array

    // dichiarazione di puntatori a stringhe che rappresentano i semi e le facce
    const char *suit[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    const char *face[FACES] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
                               "Ten", "Jack", "Queen", "King"};

    // numero di giocatori

    srand(time(NULL)); // seme per funzione random
    shuffle(deck);     // mescola le carte

    for (int player = 1; player <= numberPlayer; player++)
    {

        printf("<<<<<<<<<<The Hand of Player %d is:  \n", player);

        // reset handCards array
        for (int i = 0; i < HANDS; i++)
        {
            handCards[i][0] = 0;
            handCards[i][1] = 0;
        }

        deal(deck, handCards, face, suit);                  // distribuisci le carte
        pair(handCards, face, suit, points, player);        // coppia
        twoPair(handCards, face, suit, points, player);     // doppia coppia
        threeOfKind(handCards, face, suit, points, player); // tris
        fourOfKind(handCards, face, suit, points, player);  // poker0
        straight(handCards, face, suit, points, player);    // scala
        flush(handCards, face, suit, points, player);       // colore
        fullHouse(handCards, face, suit, points, player);   // full
        royalFlush(handCards, face, suit, points, player);  // scala reale
    }

    for (int i = 0; i < numberPlayer; i++)
    {
        if (result[i] > highestScore)
        {
            highestScore = result[i];
            winners[0] = i;
            winnerCount = 1;
        }
        else if (result[i] == highestScore)
        {
            winners[winnerCount++] = i;
        }
    }
    if (winnerCount == 1)
    {
        printf("Player %d Win!! \n", winners[0] + 1);
    }
    else
    {
        printf("Split between players:");
        for (int i = 0; i < winnerCount; i++)
        {
            printf("%d -", winners[i] + 1);
        }
        printf("Win!! \n");
    }

    return 0;
}

void shuffle(unsigned int wDeck[][FACES])
{
    size_t row;    // row number
    size_t column; // column number
    size_t card;   // counter

    for (card = 1; card <= CARDS; ++card)
    {
        do
        {
            // assegna casualmente alla carta una suit e una face nel mazzo
            row = rand() % SUITS;
            column = rand() % FACES;
        } while (wDeck[row][column] != 0);

        wDeck[row][column] = card;
    }
}

void deal(unsigned int wDeck[][FACES], unsigned int handCards[][2], const char *wFace[], const char *wSuit[])
{
    size_t row;            // row counter
    size_t column;         // column counter
    unsigned int card = 0; // card counter

    // iterazione fino a quando non si raggiunegono le mani prestabilite (HANDS= 5)
    while (card <= HANDS)
    {
        // assegnazione random
        row = rand() % SUITS;
        column = rand() % FACES;

        if (*(*(wDeck + row) + column) != 0)
        {
            handCards[card][0] = row;
            handCards[card][1] = column;

            // eliminiamo dal mazzo la carta assegnata
            *(*(wDeck + row) + column) = 0; // puntatore alla posizione specifica (array bidimesionale = array dentro array)

            printf("%5s of %-8s\n", wFace[column], wSuit[row]); // stampa la carta
            card++;
        }
    }

    puts("\n");
}

void pair(unsigned int handCards[][2], const char *wFace[], const char *wSuit[], int *points, int player)
{
    unsigned int counter[FACES] = {0};
    size_t arrayPosition = player - 1;

    // contatore per controllare se ci sono due carte con lo stesso valore
    for (size_t i = 0; i < HANDS; i++)
    {
        counter[handCards[i][1]]++;
    }

    for (size_t i = 0; i < FACES; i++)
    {
        if (counter[i] == 2)
        {

            (*(points + arrayPosition))++;
            printf("You have a pair of %s\n", wFace[i]);
        }
    }
}
void twoPair(unsigned int handCards[][2], const char *wFace[], const char *wSuit[], int *points, int player)
{
    unsigned int counter[FACES] = {0};
    size_t arrayPosition = player - 1;

    // contatore per controllare se ci sono due carte con lo stesso valore
    for (size_t i = 0; i < HANDS; i++)
    {
        counter[handCards[i][1]]++;
    }

    int pair = 0;
    for (size_t i = 0; i < FACES; i++)
    {
        if (counter[i] == 2)
        {
            pair++;
        }
    }

    if (pair == 2)
    {
        (*(points + arrayPosition))++;
        puts("You have two pair");
    }
}

void threeOfKind(unsigned int handCards[][2], const char *wFace[], const char *wSuit[], int *points, int player)
{
    unsigned int counter[FACES] = {0};
    size_t arrayPosition = player - 1;

    // contatore per controllare se ci sono due carte con lo stesso valore
    for (size_t i = 0; i < HANDS; i++)
    {
        counter[handCards[i][1]]++;
    }

    for (size_t i = 0; i < FACES; i++)
    {
        if (counter[i] == 3)
        {
            (*(points + arrayPosition))++;
            printf("You have a three of kind of %s\n", wFace[i]);
        }
    }
}

void fourOfKind(unsigned int handCards[][2], const char *wFace[], const char *wSuit[], int *points, int player)
{
    unsigned int counter[FACES] = {0};
    size_t arrayPosition = player - 1;

    // contatore per controllare se ci sono due carte con lo stesso valore
    for (size_t i = 0; i < HANDS; i++)
    {
        counter[handCards[i][1]]++;
    }

    for (size_t i = 0; i < FACES; i++)
    {
        if (counter[i] == 4)
        {
            (*(points + arrayPosition))++;
            printf("You have a four of kind of %s\n", wFace[i]);
        }
    }
}

void straight(unsigned int handCards[][2], const char *wFace[], const char *wSuit[], int *points, int player)
{
    unsigned int counter[FACES] = {0};
    unsigned int temp = 0;
    size_t arrayPosition = player - 1;

    // counter cards

    for (size_t i = 0; i < HANDS; i++)
    {
        counter[i] = handCards[i][1];
    }
    // bubble sort for order cards
    for (size_t pass = 1; pass < HANDS; pass++)
    {
        for (size_t i = 0; i < HANDS - 1; i++)
        {
            if (counter[i] > counter[i + 1])
            {
                temp = counter[i];
                counter[i] = counter[i + 1];
                counter[i + 1] = temp;
            }
        }
    }

    if (counter[0] + 1 == counter[1] && counter[1] + 1 == counter[2] && counter[2] + 1 == counter[3] && counter[3] + 1 == counter[4])
    {

        (*(points + arrayPosition))++;
        puts("You have a straight");
        printf("You have a straight from %s to %s .\n", wFace[counter[0]], wFace[counter[4]]);
    }
}

void flush(unsigned int handCards[][2], const char *wFace[], const char *wSuit[], int *points, int player)
{
    unsigned int counter[SUITS] = {0};
    size_t arrayPosition = player - 1;

    // contatore per controllare se ci sono due carte con lo stesso valore
    for (size_t i = 0; i < HANDS; i++)
    {
        counter[handCards[i][0]]++;
    }

    for (size_t i = 0; i < SUITS; i++)
    {
        if (counter[i] == 5)
        {
            (*(points + arrayPosition))++;
            printf("You have a flush of %s\n", wSuit[i]);
        }
    }
}

void fullHouse(unsigned int handCards[][2], const char *wFace[], const char *wSuit[], int *points, int player)
{
    unsigned int counter[FACES] = {0};
    size_t arrayPosition = player - 1;

    // contatore per controllare se ci sono due carte con lo stesso valore
    for (size_t i = 0; i < HANDS; i++)
    {
        counter[handCards[i][1]]++;
    }

    int pair = 0;
    int three = 0;
    for (size_t i = 0; i < FACES; i++)
    {
        if (counter[i] == 2)
        {
            pair++;
        }
        if (counter[i] == 3)
        {
            three++;
        }
    }

    if (pair == 1 && three == 1)
    {
        (*(points + arrayPosition))++;
        puts("You have a full house");
    }
}

void royalFlush(unsigned int handCards[][2], const char *wFace[], const char *wSuit[], int *points, int player)
{
    size_t arrayPosition = player - 1;
    unsigned int counter[FACES] = {0};
    unsigned int counterFlush[SUITS] = {0};
    unsigned int temp = 0;

    int straight = 0;
    int flush = 0;

    // counter cards

    for (size_t i = 0; i < HANDS; i++)
    {
        counter[i] = handCards[i][1];
    }
    // bubble sort for order cards
    for (size_t pass = 1; pass < HANDS; pass++)
    {
        for (size_t i = 0; i < HANDS - 1; i++)
        {
            if (counter[i] > counter[i + 1])
            {
                temp = counter[i];
                counter[i] = counter[i + 1];
                counter[i + 1] = temp;
            }
        }
    }

    for (size_t i = 0; i < FACES; i++)
    {

        if (counter[0] + 1 == counter[1] && counter[1] + 1 == counter[2] && counter[2] + 1 == counter[3] && counter[3] + 1 == counter[4])
        {

            straight++;
        }
    }

    // conta loe carte dello stesso seme

    for (size_t i = 0; i < HANDS; i++)
    {
        counterFlush[handCards[i][0]]++;
    }

    // verifica flush

    for (size_t i = 0; i < SUITS; i++)
    {
        if (counterFlush[i] == 5)
        {
            flush++;
        }
    }

    if (straight == 1 && flush == 1)
    {
        (*(points + arrayPosition))++;
        puts("You have a royal flush");
    }
}