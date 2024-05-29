#include <iostream>
#include "carte.h"
#include "pioche.h"
#include "main.h"
#include "defausse.h"

///Le main rassemble toute les fonctions des différents fichiers du projet et organise le déroulement d'une partie.
int main(){
    ///Initialisation des variables
    pioche p1;
    defausse def = nullptr;
    int n, num_carte;
    bool check = false;
    std::string choix;
    generer_jeu(p1);
    ///Définiton du nombre de joueurs
    do{
        std::cout << "Nombre de joueurs ? (min 2 / max 7)\n";
        std::cin >> n;
    }
    while(n > 6 or n < 2);
    hand * ens_main = distribue(n, p1);
    int i = 0;
    ///On répéte le déroulé d'une manche tant que personne n'a gagné 
    while(check == false){
        ++i;
        std::cout << "\nTour " << i << " \n";
        for(int j = 0; j < n; ++j){
            ///On trie puis affiche la main du joueur 
            std::cout << "\nJoueur " << j+1 << " :\n";
            trier_main(ens_main[j]);
            tri tab_tri = organiser_main(ens_main[j]);
            affiche_une_main(tab_tri, ens_main[j]);
            ///On demande si le joueur veut piocher ou prendre la carte de la défausse 
            if(est_vide(def) == false){
                std::cout << "\n\nEntrez d pour prendre la carte de la défausse ( ";
                affiche_def(def);
                std::cout << " )";
            }
            std::cout << "\nEntrez p pour prendre la carte de la pioche \n";
            std::cin >> choix;
            ///On enregistre son choix et on ajoute la carte correspondante à sa main
            if(choix == "d") prendre_defausse(ens_main[j], def);
            else tirer(ens_main[j], p1);
            trier_main_14(ens_main[j]);
            tab_tri = organiser_main(ens_main[j]);
            ///On regarde si le joueur à gagné 
            if(gagne15(ens_main[j], tab_tri) == true){
                std::cout << "Le joueur n° " << j+1 << "a gagné !\n";
                break;
            }
            ///Sinon on affiche sa main et on lui demande quelle carte il veut défausser 
            affiche_une_main_complete(tab_tri, ens_main[j]);
            carte sugg = suggerer_carte(ens_main[j], tab_tri);
            std::cout << "\nCarte suggérée : " << sugg.valeur << " de " << sugg.couleur << "\n"; 
            std::cout << "Entrez le n° de la carte que vous voulez defausser (0...14) :\n";
            std::cin >> num_carte;
            while(num_carte > 14 or num_carte < 0){
                std::cout << "Erreur, le chiffre doit être entre 0 et 14";
            }
            mettre_defausse(ens_main[j], num_carte, def);
            ///on verifie une deuxième fois si le joueur à gagné pour arrêter le jeu si besoin
            if(gagne14(ens_main[j], tab_tri) == true){
                std::cout << "Le joueur n° " << j+1 << "a gagné !\n";
                check = true;
            }
        }
    }
    return 0;
}