#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 7
#define LANCI 6000000

int main(void)
{
    // dichiaro dimeensione array rispetto alla costante size
    unsigned int frequency[SIZE] = {0};
    // generazione seme per la funzione rand(PS in assenza generiamo funzioni random sistematiche)
    srand(time(NULL));

    for (unsigned int roll = 1; roll <= LANCI; roll++)
    {
        size_t face = 1 + rand() % 6;
        ++frequency[face];
    }

    printf("%s%17s\n", "Face", "Frequency");

    for (size_t face = 1; face < SIZE; face++)
    {
        printf("%4d%17d\n", face, frequency[face]);
    }
}