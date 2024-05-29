#pragma once
#include <string>

///Structure qui définit une carte, elle possède une valeur, une couleur 
///et deux bolléens qui permettent de vérifier si la carte à déjà été distribuée ou si elle à déjà été mise dans une combianaison 
struct carte{
    int valeur;
    std::string couleur;
    bool verif_d;
    bool use;
};

