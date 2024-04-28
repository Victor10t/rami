#include <iostream>
#include "carte.h"
#include "pioche.h"
#include "main.h"

int main(){
    pioche p1;
    int n;
    generer_jeu(p1);
    do{
        std::cout << "Nombre de joueurs ? (min 2 / max 7)\n";
        std::cin >> n;
    }
    while(n > 7 or n < 2);
    hand * ens_main = distribue(n, p1);
    affiche_toutes_mains(n, ens_main);
    affiche_une_main(1, ens_main);
    return 0;
}