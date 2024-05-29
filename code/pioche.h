#pragma once
#include "carte.h"
#include "main.h"
#include <array>

///Structure qui définit la pioche, un tableau de 104 cartes.
struct pioche{
    carte c[104];
};

///Fonctions de pioche.cpp
void generer_jeu(pioche & p);
hand * distribue(int nb_joueurs, pioche & p);
void tirer(hand & ens_main, pioche & p1);
