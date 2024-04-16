#include "carte.h"

void init_tab_match(carte & c){
    for(int i = 1; i < 4; ++i){
        carte c1;
        c1.valeur = c.valeur;
        if(c.couleur + i > 3)
            c1.couleur = c.couleur + i - 4;
        else
            c1.couleur = c.couleur + i;
        c.tab_match[i] = c1;
    }
    carte c2;
    c2.couleur = c.couleur;
    c2.valeur = c.valeur + 1;
    c.tab_match[3] = c2;
    carte c3;
    c3.couleur = c.couleur;
    c3.valeur = c.valeur - 1;
    c.tab_match[4] = c3;
}

