#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{   // Init Variables
    int nombre_max = 100, nombre_min = 1;
    int nombre_mystere = 0;
    int nombre_client = 0;
    int replay = 1; // Boolean replay

// Boucle principale (replay)
while (replay == 1)
{
    int coups = 0; // Nombre de coups
    int gamemode = 0; // Choix du gamemode (solo ou duo)
    int lvl = 0; // Choix du level (100 ou 1000)

// Menu LVL
    printf("1. 100\n");
    printf("2. 1000\n");
    printf("Quel niveau ? ");
    scanf("%d", &lvl);
    if (lvl == 1)
        nombre_max = 100;
    else
        nombre_max = 1000;
// Menu mode
    printf("\nNiveau: %d\n---\n", nombre_max);
    printf("1. Solo\n");
    printf("2. Duo\n");
    printf("Quel mode voulez vous ? ");
    scanf("%d", &gamemode);
    // Condition Mode
    if (gamemode == 1)
    {
        srand(time(NULL));
        nombre_mystere = (rand() % (nombre_max - nombre_min +1)) + nombre_min;
    }
    else
    {
        printf("---\n\nJoueur 1 - Indiquez le nombre mystere: ");
        scanf("%d", &nombre_mystere);
    }



// Boucle de jeu
    while (nombre_client != nombre_mystere)
    {
        printf("---\nEntrez votre nombre :\n");
        scanf("%d", &nombre_client);
        coups++;

        if (nombre_client > nombre_mystere)
            printf("Plus bas\n");
        else if (nombre_client < nombre_mystere)
            printf("Plus haut\n");
        else
        {
            printf("Bravo ! vous avez reussi en %d coups\n", coups);
            printf("Voulez vous rejouez (1 = Yes | 0 = No) ? ");
            scanf("%d", &replay);
        }

        printf("-----\nNombre de coups: %d\n\n", coups);

    }

}


    return 0;
}
