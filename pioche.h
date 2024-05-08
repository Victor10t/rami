#pragma once
#include "carte.h"
#include "main.h"
#include <array>

struct pioche{
    carte c[104];
};

void generer_jeu(pioche & p);
hand * distribue(int nb_joueurs, pioche & p);
void tirer(hand & ens_main, pioche & p1);
