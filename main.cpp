#include "carte.h"
#include "pioche.h"
#include <iostream>


void affiche_toutes_mains(int nb_joueurs, hand * ens_main){
    for(int i = 0; i < nb_joueurs; ++i){
        std::cout << "\n Main n° " << i+1 << "\n";
        for(int j = 0; j < 14; ++j){
            std::cout << ens_main[i].c[j].valeur << " de " << ens_main[i].c[j].couleur << " | ";
        }
    }
}

void affiche_une_main(int num_joueur, hand * ens_main){
    std::cout << "\n Joueur n° " << num_joueur << "\n";
    for(int i = 0; i < 14; ++i){
        std::cout << ens_main[num_joueur-1].c[i].valeur << " de " << ens_main[num_joueur-1].c[i].couleur << " | ";
    }
}