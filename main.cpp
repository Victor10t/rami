#include "carte.h"
#include "pioche.h"
#include "main.h"
#include <iostream>
#include <array>


void affiche_toutes_mains(int nb_joueurs, hand * ens_main){
    for(int i = 0; i < nb_joueurs; ++i){
        std::cout << "\n Main n° " << i+1 << "\n";
        for(int j = 0; j < 14; ++j){
            std::cout << "(" << j << ") " << ens_main[i].c[j].valeur << " " << ens_main[i].c[j].couleur << " | ";
        }
    }
}

void affiche_une_main(int num_joueur, hand main){
    for(int i = 0; i < 14; ++i){
        std::cout << "(" << i << ") " << main.c[i].valeur << " " << main.c[i].couleur << " | ";
    }
}

void affiche_une_main_complete(int num_joueur, hand main){
    for(int i = 0; i < 14; ++i){
        std::cout << "(" << i << ") " << main.c[i].valeur << " " << main.c[i].couleur << " | ";
    }
    std::cout << "(14) " << main.c[14].valeur << " " << main.c[14].couleur << " | \n";
}

