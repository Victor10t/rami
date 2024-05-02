#pragma once
#include "carte.h"
#include "main.h"

struct maillon{
    carte c;
    maillon * suiv;
};

using defausse = maillon *;

void prendre_defausse(hand * & main, defausse & def);
void mettre_defausse(hand * & main, defausse & def);
