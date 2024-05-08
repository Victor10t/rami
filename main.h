#pragma once
#include "carte.h"
#include "pioche.h"

struct hand{
    carte c[15];
};

void affiche_toutes_mains(int nb_joueurs, hand * ens_main);
void affiche_une_main(int num_joueur, hand main);
void affiche_une_main_complete(int num_joueur, hand main);
