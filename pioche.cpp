#include "pioche.h"
#include "main.cpp"
#include "carte.cpp"

void generer(){
    carte * cartes_dispo;
    int n = 0;
    cartes_dispo = new carte[n];
    for(int i = 0; i < 3; ++i){
        for(int j = 1; j < 13; ++j){
            carte c_actu;
            c_actu.couleur = i;
            c_actu.valeur = j;
            cartes_dispo[n] = c_actu;
            cartes_dispo[n+1] = c_actu;
            n = n + 2;
        }
    }
}