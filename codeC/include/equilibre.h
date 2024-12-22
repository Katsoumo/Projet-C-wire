#ifndef EQUILIBRE_H
#define EQUILIBRE_H

#include "arbre.h"


int max(int a, int b);
int min(int a, int b, int c);
int min2(int a, int b);
int max2(int a, int b, int c);
PAVL rotationGauche(PAVL a);
PAVL rotationDroite(PAVL a);
PAVL doubleRotationGauche(PAVL a);
PAVL doubleRotationDroite(PAVL a);
PAVL equilibrerAVL(PAVL a);

#endif // EQUILIBRE_H
