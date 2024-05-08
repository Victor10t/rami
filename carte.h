#pragma once
#include <string>

struct carte{
    int valeur;
    std::string couleur;
    bool verif_d;
    carte * tab_match;
};

/*void init_tab_match(carte & c);*/