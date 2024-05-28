#include "defausse.h"
#include "carte.h"
#include "pioche.h"
#include "main.h"
#include <iostream>

///Cette fonction permet à un joueur de prendre la carte présente dans la défausse et de l'ajouter à sa main.
void prendre_defausse(hand & main, defausse & def){
    if (def != nullptr){
        main.c[14] = def->c; 
        defausse p = def;
        def = def->suiv;
        delete p;
        std::cout << "Le "<< main.c[14].valeur << " de " << main.c[14].couleur << " a été ajouté à votre main\n";
    }
}

///Cette fonction permet à un joueur de mettre une carte de sa main dans la défausse
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

///Cette fonction vérifie si la défausse est vide.
bool est_vide (defausse def){
    return def == nullptr;
}

///Cette fonction affiche la carte en haut de la défausse.
void affiche_def(defausse def){
    if (def != nullptr){
        std::cout << def->c.valeur << " de " << def->c.couleur;
    }
}