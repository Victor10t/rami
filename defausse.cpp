#include "defausse.h"
#include "carte.h"
#include "pioche.h"
#include "main.h"
#include <iostream>

void prendre_defausse(hand & main, defausse & def){
    if (def != nullptr){
        main.c[14] = def->c; 
        defausse p = def;
        def = def->suiv;
        delete p;
    }
}

void mettre_defausse(hand & main, int num_carte, defausse & def){
    defausse p;
    p = new maillon;
    p->c = main.c[num_carte];
    p->suiv = def;
    def = p;
    for(int i = num_carte; i < 14; ++i){
        main.c[i] = main.c[i+1];
    }
}

bool est_vide (defausse def){
    return def == nullptr;
}

void affiche_def(defausse def){
    if (def != nullptr){
        std::cout << def->c.valeur << " de " << def->c.couleur;
    }
}