#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define SUITS 4
#define FACES 13
#define CARDS 52

// prototipi

void shuffle(unsigned int wDeck[][FACES]);
void deal(unsigned int wDeck[][FACES], const char *wFace[], const char *wSuit[]);

int main()
{

    unsigned int deck[SUITS][FACES] = {0}; // array multi dimensionale carte (righe --> seme ; colonne --> valore carta da 1 a 13)
    srand(time(NULL));                     // seme per valore casuale

    shuffle(deck); // mescola le carte

    const char *suit[SUITS] = {"Cuori", "Quadri", "Fiori", "Picche"}; // inizializza array suit [4]

    // inizializza array face

    const char *face[FACES] = {"Asso", "Due", "Tre", "Quattro", "Cinque", "Sei", "Sette", "Otto", "Nove", "Dieci", "Jack", "Regina", "Re"};

    deal(deck, face, suit); // distribuisce le carte

    return 0;
}
// mescola carte
void shuffle(unsigned int wDeck[][FACES])
{
    for (size_t card = 1; card <= CARDS; ++card)
    {
        size_t row;
        size_t column;

        // possibilità di posposizione indefinita --> potrebbe non mescolarai mai una determinata carta

        do
        {
            row = rand() % SUITS;
            column = rand() % FACES;

        } while (wDeck[row][column] != 0);

        wDeck[row][column] = card;
    }
}

// distribuisci carte
void deal(unsigned int wDeck[][FACES], const char *wFace[], const char *wSuit[])
{
    for (size_t card = 1; card <= CARDS; ++card)
    {
        for (size_t row = 0; row < SUITS; ++row)
        {
            for (size_t column = 0; column < FACES; ++column)
            {
                if (wDeck[row][column] == card)
                {
                    printf("%5s di %-8s%c", wFace[column], wSuit[row], card % 2 == 0 ? '\n' : '\t');
                }
            }
        }
    }
}
