#include <stdio.h>

int main(void)
{
    int choise;
    int radius;
    int l;
    float area;
    printf("<<<<<<Welcome to IoRobot \n");
    printf("Scegli un operazione: \n");
    printf("1. Calcola Area del Cerchio \n");
    printf("2. Calcola Area del Quadrato \n");
    printf("3. Calcola Area della Sfera \n");

    scanf("%d", &choise);

    switch (choise)
    {
    case 1:

        printf("Inserisci il raggio del cerchio: \n");
        scanf("%d", &radius);

        // formula per calcolare l'area del cerchio
        area = 3.14 * radius * radius;
        printf("L'area del cerchio e: %f \n", area);
        break;

    case 2:
        printf("Inserisci il lato del quadrato: \n");
        scanf("%d", &l);
        area = l + l;
        printf("L'area del quadrato è: %f \n", area);
        break;

    case 3:

        printf("Inserisci il raggio della sfera: \n");
        scanf("%d", &radius);

        area = 4 * 3.14 * radius * radius;
        printf("L'area della sfera è: %f \n", area);
        break;

    default:
        printf("Operazione non valida \n");
        break;
    }
    return 0;
}