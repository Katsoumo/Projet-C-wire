#include <stdio.h>
#include <stdlib.h>

#include "equilibre.h"
#include "arbre.h"



int maximum(int a, int b) {
    if (a >= b) {
        return a;
    } else {
        return b;
    }
}

int minimum(int a, int b, int c) {
    int min = a;

    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    return min;
}

int minimum2(int a, int b) {
    if (a <= b) {
        return a;
    } else {
        return b;
    }
}

int maximum2(int a, int b, int c) {
    int max = a;

    if (b > max) {
        max = b;
    }
    if (c > max) {
        max = c;
    }
    return max;
}

PAVL rotationGauche(PAVL a) {
    PAVL pivot;
    int ba_a, ba_p;
    pivot = a->fd;
    a->fd = pivot->fg;
    pivot->fg = a;

    ba_a = a->balance;
    ba_p = pivot->balance;

    a->balance = ba_a - maximum(ba_p, 0) - 1;
    pivot->balance = minimum(ba_a - 2, ba_a + ba_p - 2, ba_p - 1);

    a = pivot;
    return a;
}

PAVL rotationDroite(PAVL a) {
    PAVL pivot;
    int ba_a, ba_p;
    pivot = a->fg;
    a->fg = pivot->fd;
    pivot->fd = a;

    ba_a = a->balance;
    ba_p = pivot->balance;

    a->balance = ba_a - minimum2(ba_p, 0) + 1;
    pivot->balance = maximum2(ba_a + 2, ba_a + ba_p + 2, ba_p + 1);

    a = pivot;
    return a;
}

PAVL rotationDoubleGauche(PAVL a) {
    a->fd = rotationDroite(a->fd);
    return rotationGauche(a);
}

PAVL rotationDoubleDroite(PAVL a) {
    a->fg = rotationGauche(a->fg);
    return rotationDroite(a);
}

PAVL equilibrerAVL(PAVL a) {
    if (a->balance >= 2) {
        if (a->fd->balance >= 0) {
            return rotationGauche(a);
        } else {
            return rotationDoubleGauche(a);
        }
    } else if (a->balance <= -2) {
        if (a->fg->balance <= 0) {
            return rotationDroite(a);
        } else {
            return rotationDoubleDroite(a);
        }
    }
    return a;
}
