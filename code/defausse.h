#pragma once
#include "carte.h"
#include "pioche.h"
#include "main.h"

///Strucutre qui représente la défausse,
///une liste chainée ou chaque maillon est une carte et un pointeur qui pointe vers la suivante 
struct maillon{
    carte c;
    maillon * suiv;
};

using defausse = maillon *;

///Fonctions de defausse.cpp
void prendre_defausse(hand & main, defausse & def);
void mettre_defausse(hand & main, int num_carte, defausse & def);
bool est_vide (defausse def);
void affiche_def(defausse def);
