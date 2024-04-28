#pragma once
#include <string>

struct carte{
    int valeur;
    int couleur;
    carte * tab_match;
    bool verif_d;
};

void init_tab_match(carte & c);