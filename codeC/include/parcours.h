#ifndef PARCOURS_H
#define PARCOURS_H

#include "arbre.h"


void traiterNoeud(PAVL a, FILE *fichier);
void parcoursInfixe(PAVL a, FILE *fichier);
void remplirCSV(PAVL a, FILE *fichier);

#endif // PARCOURS_H
