#pragma once
#include "carte.h"
#include "main.h"
#include <array>

struct pioche{
    carte c[104];
};

void generer_jeu(pioche & p);
void melange(pioche & p);
void distribue(int nb_joueur, pioche & p);
/*
carte tirer(pioche & p, hand & m);*/
