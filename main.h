#pragma once
#include "carte.h"
#include "pioche.h"

struct hand{
    carte c[15];
    carte paire[15];
    int paire_taille;
};

struct combinaison {
    carte c[4];
    int taille_c;
};

struct presqueCombinaison {
    carte c[2];
};

struct tri {
    int taille_a;
    int taille_b;
    combinaison comb_f[10]; 
    presqueCombinaison presque_comb[10]; 
    carte non_comb[15];
};

void affiche_toutes_mains(int nb_joueurs, hand * ens_main);
void affiche_une_main(tri tri, hand & main);
void affiche_une_main_complete(tri tri, hand & main);
void echange(hand & main, int x, int y);
void trier_main(hand & main);
bool check_brelan(hand main);
bool check_carre(hand main);
bool check_suite(hand main);
bool check_paire_suite(hand main);
bool check_paire(hand main);
void trier_main_14 (hand & main);
tri organiser_main(hand &main);
bool gagne_14(hand main, tri tri);
bool gagne_15(hand main, tri tri);

