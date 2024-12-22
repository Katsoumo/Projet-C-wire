#ifndef TRAITEMENT_H
#define TRAITEMENT_H

#include <stdio.h>
#include "arbre.h"
#include "equilibre.h"
#include "parcours.h"

#define SIZE 100000
#define JETON 64


PAVL rechercher(PAVL a, long id);
int mettreAJourCapacite(PAVL* a, long id, long nouvelleCapacite);
int ajouterConsommation(PAVL *a, long id, long nouvelleCons);
void traiterFichier(const char *nomFichier, PAVL *arbre, int *h);

#endif // TRAITEMENT_H
