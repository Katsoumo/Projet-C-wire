#include <stdio.h>
#include <stdlib.h>

#include "arbre.h"
#include "equilibre.h"

PAVL creerAVL(Station* elt) {
    if (elt == NULL) {
        printf("La station n'existe pas.\n");
        exit(3);
    }
    PAVL a = malloc(sizeof(AVL));
    if (a == NULL) {
        printf("Erreur : Échec de l'allocation mémoire pour le nœud AVL.\n");
        exit(4);
    }

    a->elt.id_station = malloc(sizeof(long));
    a->elt.capacite = malloc(sizeof(long));
    a->elt.cons = malloc(sizeof(long));

    if (a->elt.id_station == NULL || a->elt.capacite == NULL || a->elt.cons == NULL) {
        printf("Erreur : Échec de l'allocation mémoire pour les données de la station.\n");
        exit(5);
    }

    *(a->elt.id_station) = *(elt->id_station);
    *(a->elt.capacite) = *(elt->capacite);
    *(a->elt.cons) = *(elt->cons);

    a->fg = NULL;
    a->fd = NULL;
    a->balance = 0;

    return a;
}

Station* creerStation(long id, long capacite, long cons) {
    Station* nouvelleStation = malloc(sizeof(Station));
    if (nouvelleStation == NULL) {
        printf("Erreur : Échec de l'allocation mémoire pour la station.\n");
        exit(1);
    }

    nouvelleStation->id_station = malloc(sizeof(long));
    nouvelleStation->capacite = malloc(sizeof(long));
    nouvelleStation->cons = malloc(sizeof(long));

    if (nouvelleStation->id_station == NULL || nouvelleStation->capacite == NULL || nouvelleStation->cons == NULL) {
        printf("Erreur : Échec de l'allocation mémoire pour les champs de la station.\n");
        exit(2);
    }

    *(nouvelleStation->id_station) = id;
    *(nouvelleStation->capacite) = capacite;
    *(nouvelleStation->cons) = cons;

    return nouvelleStation;
}

PAVL insertionAVL(PAVL a, Station elt, int* h) {
    if (a == NULL) {
        *h = 1;
        return creerAVL(&elt);
    }

    if (*(elt.id_station) < *(a->elt.id_station)) {
        a->fg = insertionAVL(a->fg, elt, h);
    }
    else if (*(elt.id_station) > *(a->elt.id_station)) {
        a->fd = insertionAVL(a->fd, elt, h);
    }
    else {
        *h = 0;
        return a;
    }

    if (*h != 0) {
        a->balance += (*h);
        a = equilibrerAVL(a);

        if (a->balance == 0) {
            *h = 0;
        } else {
            *h = 1;
        }
    }

    return a;
}
