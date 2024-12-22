#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "traitement.h"
#include "arbre.h"
#include "equilibre.h"
#include "parcours.h"

#define SIZE 100000

PAVL rechercher(PAVL a, long id) {
    while (a != NULL) {
        if (*(a->elt.id_station) == id) {
            return a;
        } else if (id < *(a->elt.id_station)) {
            a = a->fg;
        } else {
            a = a->fd;
        }
    }
    return NULL;
}

int mettreAJourCapacite(PAVL* a, long id, long nouvelle_capacite) {
    PAVL noeud = *a;
    if (rechercher(noeud, id)) {
        noeud->elt.capacite = malloc(sizeof(long));
        if (noeud->elt.capacite != NULL) {
            *(noeud->elt.capacite) = nouvelle_capacite;
            return 1;
        }
    }
    return 0;
}

int ajouterConsommation(PAVL* a, long id, long nouvelle_cons) {
    PAVL noeud = rechercher(*a, id);

    if (noeud != NULL) {
        *(noeud->elt.cons) += nouvelle_cons;
        return 1;
    }

    return 0;
}

void traiterFichier(const char *nom_fichier, PAVL *arbre, int *h) {
    FILE *fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        printf("Impossible d'ouvrir le fichier");
        exit(2);
    }

    char *tampon = malloc(SIZE * sizeof(char));
    if (tampon == NULL) {
        printf("Échec de l'allocation mémoire pour le tampon");
        fclose(fichier);
        exit(3);
    }

    long id, capacite, cons;

    fgets(tampon, SIZE, fichier);
    while (fgets(tampon, SIZE, fichier) != NULL) {
        id = 0;
        capacite = -1;
        cons = 0;

        int nbtokens = sscanf(tampon, "%ld;%ld;%ld", &id, &capacite, &cons);
        if (nbtokens == 3) {
            if (!mettreAJourCapacite(arbre, id, capacite) || !ajouterConsommation(arbre, id, cons)) {
                Station *nouvelleStation = creerStation(id, capacite, cons);
                *arbre = insertionAVL(*arbre, *nouvelleStation, h);
            }
        } else {
            printf("Format de ligne invalide dans le fichier : %s\n", tampon);
        }
    }

    free(tampon);
    fclose(fichier);
}
