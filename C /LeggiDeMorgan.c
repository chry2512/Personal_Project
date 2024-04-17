#include <stdio.h>

int main(void)


{

    /*
    // Legge 1: !(A && B) è lo stesso di (!A || !B)
    // Legge 2: !(A || B) è lo stesso di (!A && !B)
    */
    int x = 10;
    int y = 1;
    int a = 3;
    int b = 3;
    int g = 5;
    int q = 1;
    int i = 2;
    int j = 9;
    

    if ((!(x < 5) && !(y >= 7)) == (!((x < 5) || (y >= 7))))
        printf("La condizione e' uguale\n");
    else
        printf("La condizione e' diversa\n");

        puts("!((x < 5) || (y >= 7))");

    return 0;
}