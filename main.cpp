#include "carte.h"
#include "pioche.h"
#include "main.h"
#include <iostream>
#include <algorithm>


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
    std::cout << "\n Tab combinaison :\n";
    for(int i = 0; i < main.paire_taille; ++i){
        std::cout << main.paire[i].valeur << " " << main.paire[i].couleur << " | ";
    }
}

void affiche_une_main_complete(int num_joueur, hand main){
    for(int i = 0; i < 14; ++i){
        std::cout << "(" << i << ") " << main.c[i].valeur << " " << main.c[i].couleur << " | ";
    }
    std::cout << "(14) " << main.c[14].valeur << " " << main.c[14].couleur << " | \n";
    std::cout << "\n Tab combinaison :\n";
    for(int i = 0; i < main.paire_taille; ++i){
        std::cout << main.paire[i].valeur << " " << main.paire[i].couleur << " | ";
    }
}

bool check_brelan(hand &main){
    for(int i = 0; i < 12; ++i){
        int count = 1;
        for(int j = i+1; j < 14; ++j){
            if(main.c[i].valeur == main.c[j].valeur){
                count++;
            }
        }
        if(count >= 3){
            return true;
        }
    }
    return false;
}

bool check_carre(hand &main){
    for(int i = 0; i < 14; ++i){
        int count = 1;
        for(int j = i+1; j < 15; ++j){
            if(main.c[i].valeur == main.c[j].valeur){
                count++;
            }
        }
        if(count == 4){
            return true;
        }
    }
    return false;
}

bool check_suite(hand &main){
    std::sort(main.c, main.c + 14, [](const carte &a, const carte &b) {
        return a.valeur < b.valeur;
    });

    int count = 1;
    for(int i = 0; i < 14; ++i){
        if(main.c[i].valeur == main.c[i+1].valeur - 1 && main.c[i].couleur == main.c[i+1].couleur){
            count++;
            if(count >= 3){
                return true;
            }
        }else{
            count = 1;
        }
    }
    return false;
}

void echange (hand & main, int x, int y)
{
	carte z = main.c[x];
    main.c[x] = main.c[y]; 
    main.c[y] = z;
}

void trier_main (hand & main)
{
	for (int i = 13; i > 0; --i)
	{
		int p = 0;
		for (int j = 1; j <= i; ++j)
			if (main.c[j].valeur > main.c[p].valeur)
				p = j;
		echange(main, p, i);
	}
}

void store_combinations(hand &main){
    main.paire_taille = 0;
    // Check and store brelan 
    if(check_brelan(main) == true){
        trier_main(main);
        for(int i = 0; i < 12; ++i){
            if(main.c[i].valeur == main.c[i+1].valeur && main.c[i].valeur == main.c[i+2].valeur){
                for(int j = 0; j < 3; ++j){
                    main.paire[main.paire_taille] = main.c[i+j];
                    ++main.paire_taille;
                }
            }
        }
    }
}


        /*for(int i = 0; i < 13; ++i){
            if(main.c[i].valeur == main.c[i+1].valeur and main.c[i].valeur == main.c[i+2].valeur){
                for(int j = 0; j < 3; ++j){
                    main.paire[main.paire_taille] = main.c[i+j];
                    ++main.paire_taille;
                    std::cout << main.c[i+j].valeur << " " << main.c[i+j].couleur << " | ";
                }
                std::cout << "\n";
            }
        }
    }*/

    /*for(int i = 0; i < 14; ++i){
        int count = 1;
        for(int j = i+1; j < 15; ++j){
            if(main.c[i].valeur == main.c[j].valeur){
                count++;
            }
        }
        if(count >= 3){
            main.paire[main.paire_taille] = main.c[i];
            ++main.paire_taille;
            for(int j = i; j < i+3; ++j){
                main.paire[main.paire_taille++] = main.c[j];
            }
            i += 2; // Skip to the next different value
        }
    }

    // Check and store carre
    for(int i = 0; i < 14; ++i){
        int count = 1;
        for(int j = i+1; j < 15; ++j){
            if(main.c[i].valeur == main.c[j].valeur){
                count++;
            }
        }
        if(count == 4){
            for(int j = i; j < i+4; ++j){
                main.paire[main.paire_taille++] = main.c[j];
            }
            i += 3; // Skip to the next different value
        }
    }

    // Check and store suite
    std::sort(main.c, main.c + 14, [](const carte &a, const carte &b) {
        return a.valeur < b.valeur;
    });

    int count = 1;
    for(int i = 0; i < 14; ++i){
        if(main.c[i].valeur == main.c[i+1].valeur - 1 && main.c[i].couleur == main.c[i+1].couleur){
            count++;
            if(count >= 3){
                for(int j = i-2; j < i+1; ++j){
                    main.paire[main.paire_taille++] = main.c[j];
                }
                i += 2; // Skip to the next different value
            }
        }else{
            count = 1;
        }
    }*/
