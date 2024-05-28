#pragma once
#include "carte.h"
#include "pioche.h"

///Structure qui représente une main de joueur. 
///Elle contient un tableau de cartes (c), un tableau de paires de cartes (paire), et la taille du tableau de paires (paire_taille).
struct hand{
    carte c[15];
    carte paire[15];
    int paire_taille;
};

///Structure qui représente une combinaison de cartes. 
///Elle contient un tableau de cartes (c) et la taille de ce tableau (taille_c).
struct combinaison {
    carte c[4];
    int taille_c;
};

///Structure qui représente une demi-combinaison de cartes, une sorte de pré-combinaison. 
///Elle contient un tableau de deux cartes (c).
struct presqueCombinaison {
    carte c[2];
};

///Structure qui représente le résultat du tri des cartes d'une main. 
///Elle contient le nombre de combinaisons complètes (taille_a), le nombre de demi-combinaisons (taille_b), 
///un tableau de combinaisons (comb_f), un tableau de demi-combinaisons (presque_comb), et un tableau de cartes non utilisées (non_comb).
struct tri {
    int taille_a;
    int taille_b;
    combinaison comb_f[10]; 
    presqueCombinaison presque_comb[10]; 
    carte non_comb[15];
};

///Définition de toute les fonctions de main.cpp
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
bool gagne14(hand main, tri tri);
bool gagne15(hand main, tri tri);

