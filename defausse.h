#pragma once
#include "carte.h"
#include "pioche.h"
#include "main.h"

struct maillon{
    carte c;
    maillon * suiv;
};

using defausse = maillon *;

void prendre_defausse(hand & main, defausse & def);
void mettre_defausse(hand & main, int num_carte, defausse & def);
bool est_vide (defausse def);
void affiche_def(defausse def);
