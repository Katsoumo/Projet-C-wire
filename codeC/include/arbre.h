#ifndef ARBRE_H
#define ARBRE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long *id_station;
    long *capacite;
    long *cons;
} Station;

typedef struct AVL {
    Station elt;
    struct AVL *fg;
    struct AVL *fd;
    int balance;
} AVL;

typedef AVL* PAVL;


PAVL creerAVL(Station* elt);
Station* creerStation(long id, long capacite, long cons);

#endif // ARBRE_H
