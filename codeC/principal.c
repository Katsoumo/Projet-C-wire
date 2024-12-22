#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "traitement.h"
#include "parcours.h"

int main(int argc, char *argv[]) {
    /*if (argc != 4) {
        printf("Trop d'arguments ou pas assez ! Il doit y en avoir exactement 3 !!\n");
        exit(1);
    }*/

    const char *nom_fichier = argv[1];
    printf("%s", argv[1]);
    const char *fichier_final = argv[2];
    PAVL arbre = NULL;
    int hauteur = 0;

    TraiterFichier(nom_fichier, &arbre, &hauteur);

    FILE *fichier = fopen(fichier_final, "w");
    if (fichier == NULL) {
        printf("Impossible d'ouvrir le fichier %s en écriture.\n", fichier_final);
        exit(1);
    }

    remplirCSV(arbre, fichier);

    fclose(fichier);
    return 0;
}
