#include "pioche.h"
#include "carte.h"
#include <iostream>
#include <cstdlib>
#include <string>

///Cette fonction génère un jeu de cartes en remplissant la pioche avec 
///2 cartes de chaque couleur (coeur, carreau, trèfle, pique) pour chaque valeur allant de 1 à 13.
void generer_jeu(pioche & p){
    std::string couleur[] = {"♥", "♦", "♠", "♣"};
    int n = 0;
    for(int i = 0; i < 4; ++i){
        for(int j = 1; j < 14; ++j){
            carte c_actu;
            c_actu.couleur = couleur[i];
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

///Cette fonction distribue aléatoirement 14 cartes à chaque joueur parmi les cartes de la pioche. 
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

///Cette fonction permet à un joueur de tirer une carte de la pioche.
void tirer(hand & main, pioche & p1){
    int a = rand() % 104;
    while(p1.c[a].verif_d != true){
        a = rand() % 104;
    }
    main.c[14] = p1.c[a];
    p1.c[a].verif_d = false;
    std::cout << "Vous avez pioché le " << main.c[14].valeur << " de " << main.c[14].couleur << "\n";
}