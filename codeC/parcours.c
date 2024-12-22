#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parcours.h"
#include "arbre.h"

void traiterNoeud(PAVL a, FILE *fichier) {
    if (a->elt.id_station == NULL || a->elt.capacite == NULL || a->elt.cons == NULL) {
        printf("Erreur : Pointeur nul dans les données de la station.\n");
        exit(46);
    }
    fprintf(fichier, "%ld; %ld; %ld\n", *(a->elt.id_station), *(a->elt.capacite), *(a->elt.cons));
}

void parcoursInfixe(PAVL a, FILE *fichier) {
    if (a != NULL) {
        parcoursInfixe(a->fg, fichier);
        traiterNoeud(a, fichier);
        parcoursInfixe(a->fd, fichier);
    }
}

void remplirCSV(PAVL a, FILE *fichier) {
    if (fichier == NULL) {
        printf("Erreur : Le fichier n'a pas été ouvert.\n");
        exit(47);
    }
    fprintf(fichier, "Station ; Capacité ; Consommation\n");
    parcoursInfixe(a, fichier);
}
