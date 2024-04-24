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

void melange(pioche & p){
    for(int i = 0; i < 104; ++i){
        int a = rand() % 104;
        carte z = p.c[i]; 
        p.c[i] = p.c[a]; 
        p.c[a] = z;
    }
    /*std::cout << "\nPioche mélangée : \n";
    for(int i = 0; i < 104; ++i){
        std::cout << p.c[i].valeur << " de " << p.c[i].couleur << " | ";
    }*/
}

void distribue(int nb_joueurs, pioche & p){
	hand * ens_main = new hand[nb_joueurs];
	for(int i = 0; i < 14; ++i){
        for(int j = 0; j < nb_joueurs; ++j){
            ens_main[j].c[i] = p.c[j + i*nb_joueurs];
        }
    }
    std::cout << "Ensemble de main : ";
    for(int i = 0; i < nb_joueurs; ++i){
        std::cout << "\nMain n°" << i << "\n";
        for(int j = 0; j < 14; ++j){
            std::cout << ens_main[i].c[j].valeur << " de " << ens_main[i].c[j].couleur << " | ";
        }
    }
}