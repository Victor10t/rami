#pragma once
#include "carte.h"
#include "pioche.h"

struct hand{
    carte c[15];
    carte paire[15];
    int paire_taille;
};

void affiche_toutes_mains(int nb_joueurs, hand * ens_main);
void affiche_une_main(int num_joueur, hand main);
void affiche_une_main_complete(int num_joueur, hand main);
bool check_brelan(hand &main);
bool check_carre(hand &main);
bool check_suite(hand &main);
void store_combinations(hand &main);

