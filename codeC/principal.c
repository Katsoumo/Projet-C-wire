#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>  
#include <sys/stat.h> 
#include <sys/types.h>

#include "arbre.h"
#include "parcours.h"
#include "traitement.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <fichier_input>\n", argv[0]);
        return 1;
    }

    const char *fichierInput = argv[1];
    const char *dossierTmp = "../tmp";        
    const char *fichierOutput = "../tmp/output.csv"; 

    
    if (access(dossierTmp, F_OK) != 0) {
        if (mkdir(dossierTmp, 0777) != 0) {
            perror("Erreur : Impossible de créer le dossier tmp");
            return 3;
        }
    }

    PAVL arbreAVL = NULL;  
    int hauteur = 0;       

   
    traiterFichier(fichierInput, &arbreAVL, &hauteur);

    if (!arbreAVL) {
        fprintf(stderr, "Erreur : L'arbre AVL est vide après le traitement du fichier.\n");
        return 2;
    }

    
    creerCSV(arbreAVL, fichierOutput);

    printf("Les données triées ont été exportées dans : %s\n", fichierOutput);
    return 0;
}

