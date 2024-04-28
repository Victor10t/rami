#include "pioche.h"
#include "carte.h"
#include <iostream>
#include <cstdlib>

void generer_jeu(pioche & p){
    int n = 0;
    for(int i = 0; i < 4; ++i){
        for(int j = 1; j < 14; ++j){
            carte c_actu;
            c_actu.couleur = i;
            c_actu.valeur = j;
            c_actu.verif_d = true;
            p.c[n] = c_actu;
            p.c[n+1] = c_actu;
            n = n + 2;
        }
    }
    /*std::cout << "Pioche non mélangée : \n";
    for(int i = 0; i < 104; ++i){
        std::cout << p.c[i].valeur << " de " << p.c[i].couleur << "| ";
    }*/
}

hand * distribue(int nb_joueurs, pioche & p){
    hand * ens_main = new hand[nb_joueurs];
    for(int i = 0; i < nb_joueurs; ++i){
        for(int j = 0; j < 14; ++j){
            int a = rand() % 104;
            while(p.c[a].verif_d != true){
                a = rand() % 104;
            }
            ens_main[i].c[j] = p.c[a];
            p.c[a].verif_d = false;
        }
    }
    return ens_main;
}

