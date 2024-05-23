#include <iostream>
#include "carte.h"
#include "pioche.h"
#include "main.h"
#include "defausse.h"

int main(){
    pioche p1;
    defausse def;
    int n, num_carte;
    std::string choix;
    generer_jeu(p1);
    do{
        std::cout << "Nombre de joueurs ? (min 2 / max 7)\n";
        std::cin >> n;
    }
    while(n > 6 or n < 2);
    hand * ens_main = distribue(n, p1);
    
    for(int i = 0; i < 10; i++){
        std::cout << "\nTour " << i+1 << " \n";
        for(int j = 0; j < n; ++j){
            std::cout << "\nJoueur " << j+1 << " :\n";
            trier_main(ens_main[j]);
            tri tab_tri = organiser_main(ens_main[j]);
            affiche_une_main(tab_tri, ens_main[j]);
            if(est_vide(def) == false){
                std::cout << "\n\nEntrez d pour prendre la carte de la défausse ( ";
                affiche_def(def);
                std::cout << " )";
            }
            std::cout << "\nEntrez p pour prendre la carte de la pioche \n";
            std::cin >> choix;
            if(choix == "d") prendre_defausse(ens_main[j], def);
            else tirer(ens_main[j], p1);
            trier_main_14(ens_main[j]);
            tab_tri = organiser_main(ens_main[j]);
            affiche_une_main_complete(tab_tri, ens_main[j]);
            std::cout << "Entrez le n° de la carte que vous voulez defausser (0...14) :\n";
            std::cin >> num_carte;
            mettre_defausse(ens_main[j], num_carte, def);
        }
    }


    /*affiche_toutes_mains(n, ens_main);
    tirer(ens_main[0], p1);
    affiche_une_main_complete(1, ens_main[0]);
    mettre_defausse(ens_main[0], 2, def);
    affiche_une_main(1, ens_main[0]);
    prendre_defausse(ens_main[1], def);
    affiche_une_main_complete(2, ens_main[1]);*/
    return 0;
}