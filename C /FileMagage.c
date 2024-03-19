#include<stdio.h>

void scrittura (FILE *file);
void lettura (FILE *file);
void addDati(FILE *file);
void deleteFile(FILE *file);



int main()
{
        
    // apre file
    FILE *file = fopen("file.txt", "r");
    int operazione;

    if(file != NULL)
    {

        printf("File aperto correttamente\n");
        scrittura(file);

        printf("Scegliere cosa fare:\n");
        printf("1. Leggere il file\n");
        printf("2. Aggiungere dati al file\n");
        printf("3. Eliminare il file\n");

        scanf("%d", &operazione);

        switch(operazione)
        {
            case 1:
                lettura(file);
                break;
            case 2:
                addDati(file);
                break;
            case 3:
                deleteFile(file);
                break;
            default:
                printf("Operazione non valida\n");
                break;
        }
        
        fclose(file);

    }else
    {
        printf("Errore nell'apertura del file\n");
    }
   
    return 0;
}  

void scrittura (FILE *file)
{
    printf("Inserisci il testo da scrivere nel file\n");
    fprintf(file, "Ciao mondo\n");
}

void lettura (FILE *file)
{
    char buffer[100];

    while(fscanf(file, "%s", buffer) != EOF)
    {
        printf("%s\n", buffer);
    }   

    printf("\nDati letti con successo!!\n");

}

void addDati(FILE *file)
{
    fopen("file.txt", "a");
}

void deleteFile(FILE *file)
{
    if(remove("file.txt")== 0)
    {
        printf("File eliminato con successo\n");
    }else{
        printf("Errore nell'eliminazione del file\n");
    }
}
