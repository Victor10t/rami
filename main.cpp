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

void affiche_une_main(tri tri, hand &main){
    for(int i = 0; i < 14; ++i){
        std::cout << "(" << i << ") " << main.c[i].valeur << " " << main.c[i].couleur << " | ";
    }
    std::cout << "\n Tab combinaison :\n";
    for(int i = 0; i < tri.taille_a; ++i){
        for(int j = 0; j < tri.comb_f[i].taille_c; ++j){
            std::cout << tri.comb_f[i].c[j].valeur << " " << tri.comb_f[i].c[j].couleur << " | ";
        }
        std::cout << std::endl;
    }
    std::cout << "\n Tab demi-combinaison :\n";
    for(int i = 0; i < tri.taille_b; ++i){
        for(int j = 0; j < 2; ++j){
            std::cout << tri.presque_comb[i].c[j].valeur << " " << tri.presque_comb[i].c[j].couleur << " | ";
        }
        std::cout << std::endl;
    }
    std::cout << "\n Carte non-utilisée :\n";
    for(int i = 0; i < 14; ++i){
        if(main.c[i].use == false){
            std::cout << main.c[i].valeur << " " << main.c[i].couleur << " | ";
        }
    }
    for(int i = 0; i < 14; ++i){
        if(main.c[i].use == true){
            main.c[i].use = false;
        }
    }
}



void affiche_une_main_complete(tri tri, hand & main){
    for(int i = 0; i < 15; ++i){
        std::cout << "(" << i << ") " << main.c[i].valeur << " " << main.c[i].couleur << " | ";
    }
    std::cout << "\n Tab combinaison :\n";
    for(int i = 0; i < tri.taille_a; ++i){
        std::cout << "\n taille_c : " << tri.comb_f[i].taille_c << "\n";
        for(int j = 0; j < tri.comb_f[i].taille_c; ++j){
            std::cout << tri.comb_f[i].c[j].valeur << " " << tri.comb_f[i].c[j].couleur << " | ";
        }
        std::cout << std::endl;
    }
    std::cout << "\n Tab demi-combinaison :\n";
    for(int i = 0; i < tri.taille_b; ++i){
        for(int j = 0; j < 2; ++j){
            std::cout << tri.presque_comb[i].c[j].valeur << " " << tri.presque_comb[i].c[j].couleur << " | ";
        }
        std::cout << std::endl;
    }
    std::cout << "\n Carte non-utilisée :\n";
    for(int i = 0; i < 15; ++i){
        if(main.c[i].use == false){
            std::cout << main.c[i].valeur << " " << main.c[i].couleur << " | ";
        }
    }
    for(int i = 0; i < 15; ++i){
        if(main.c[i].use == true){
            main.c[i].use = false;
        }
    }
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

void trier_main_14 (hand & main)
{
	for (int i = 14; i > 0; --i)
	{
		int p = 0;
		for (int j = 1; j <= i; ++j)
			if (main.c[j].valeur > main.c[p].valeur)
				p = j;
		echange(main, p, i);
	}
}

bool check_brelan(hand main){
    for(int i = 0; i < 14; ++i){
        int count = 1;
        for(int j = i+1; j < 15; ++j){
            if(main.c[i].use == false && main.c[j].use == false){
                if(main.c[i].valeur == main.c[j].valeur && main.c[i].couleur != main.c[j].couleur){
                    count++;
                }
            }
        }
        if(count >= 3){
            return true;
        }
    }
    return false;
}

bool check_carre(hand main){
    for(int i = 0; i < 14; ++i){
        int count = 1;
        for(int j = i+1; j < 15; ++j){
            if(main.c[i].use == false && main.c[j].valeur){
                if(main.c[i].valeur == main.c[j].valeur && main.c[i].couleur != main.c[j].couleur){
                    count++;
                }
            }
        }
        if(count == 4){
            return true;
        }
    }
    return false;
}

bool check_suite(hand main){
    trier_main(main);
    int count = 1;
    for(int i = 0; i <= 11; ++i){
        if(main.c[i].valeur == main.c[i+1].valeur - 1 && main.c[i].couleur == main.c[i+1].couleur && main.c[i].use == false && main.c[i+1].use == false){
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

bool check_paire_suite(hand main){
    trier_main(main);
    int count = 1;
    for(int i = 0; i < 14; ++i){
        if(main.c[i].use == false && main.c[i+1].use == false){
            if(main.c[i].valeur == main.c[i+1].valeur - 1 && main.c[i].couleur == main.c[i+1].couleur){
                count++;
                if(count >= 2){
                    return true;
                }
            }
        }else{
            count = 1;
        }
    }
    return false;
}

bool check_paire(hand main){
    int count = 1;
    for(int i = 0; i < 14; ++i){
        for(int j = i+1; j < 15; ++j){
            if(main.c[i].use == false && main.c[i+1].use == false){
                if(main.c[i].valeur == main.c[j].valeur && main.c[i].couleur != main.c[j].couleur){
                    count++;
                }
            }
        }
        if(count >= 2){
            return true;
        }
    }
    return false;
}

tri organiser_main(hand &main){
    trier_main(main);
    tri tri;
    tri.taille_a = 0;
    tri.taille_b = 0;
    int index = 0;

    // Vérifier et stocker les carrés
    while(check_carre(main)){
        trier_main(main);
        for(int i = 0; i < 12; ++i){
            if(main.c[i].use == false && main.c[i+1].use == false && main.c[i+2].use == false && main.c[i+3].use == false){
                if(main.c[i].valeur == main.c[i+1].valeur 
                && main.c[i].valeur == main.c[i+2].valeur 
                && main.c[i].valeur == main.c[i+3].valeur
                && main.c[i].couleur != main.c[i+1].couleur
                && main.c[i].couleur != main.c[i+2].couleur
                && main.c[i].couleur != main.c[i+3].couleur
                && main.c[i+1].couleur != main.c[i+2].couleur
                && main.c[i+1].couleur != main.c[i+3].couleur
                && main.c[i+2].couleur != main.c[i+3].couleur){
                    for(int j = 0; j < 4; ++j){
                        tri.comb_f[tri.taille_a].c[j] = main.c[i+j];
                        main.c[i+j].use = true;
                    }
                    tri.comb_f[tri.taille_a].taille_c = 4;
                    ++tri.taille_a;
                }
            }
        }
    }
    // Vérifier et stocker les brelans
    while(check_brelan(main)){
        trier_main(main);
        for(int i = 0; i < 13; ++i){
            if(main.c[i].use == false && main.c[i+1].use == false && main.c[i+2].use == false){
                if(main.c[i].valeur == main.c[i+1].valeur 
                && main.c[i].valeur == main.c[i+2].valeur
                && main.c[i].couleur != main.c[i+1].couleur
                && main.c[i].couleur != main.c[i+2].couleur){
                    for(int j = 0; j < 3; ++j){
                        tri.comb_f[tri.taille_a].c[j] = main.c[i+j];
                        main.c[i+j].use = true;
                    }
                    tri.comb_f[tri.taille_a].taille_c = 3;
                    ++tri.taille_a;
                }
            }
        }
    }

    // Vérifier et stocker les suites
    while(check_suite(main)){
        trier_main(main); 
        for(int i = 0; i < 13; ++i){
            if(main.c[i].use == false){
                int count = 1;
                int j = i;
                while(main.c[j].use == false && j < 14 && main.c[j].valeur == main.c[j+1].valeur - 1 && main.c[j].couleur == main.c[j+1].couleur){
                    count++;
                    j++;
                }
                if(count >= 3){
                    for(int k = 0; k < count; ++k){
                        tri.comb_f[tri.taille_a].c[k] = main.c[i+k];
                        main.c[i+k].use = true;
                    }
                    tri.comb_f[tri.taille_a].taille_c = count;
                    ++tri.taille_a;
                }
            }
        }
    }

    // Vérifier et stocker les paires
    while(check_paire(main)){
        trier_main(main);
        for(int i = 0; i < 14; ++i){
            if(main.c[i].use == false && main.c[i+1].use == false){
                if(main.c[i].valeur == main.c[i+1].valeur && main.c[i].couleur != main.c[i+1].couleur){
                    for(int j = 0; j < 2; ++j){
                        tri.presque_comb[tri.taille_b].c[j] = main.c[i+j];
                        main.c[i+j].use = true;
                    }
                    ++tri.taille_b;
                }
            }
        }
    }

    // Vérifier et stocker les paires en suite
    while(check_paire_suite(main)){
        trier_main(main);
        for(int i = 0; i < 14; ++i){
            if(main.c[i].use == false && main.c[i+1].use == false){
                if(main.c[i].valeur == main.c[i+1].valeur - 1 && main.c[i].couleur == main.c[i+1].couleur){
                    for(int j = 0; j < 2; ++j){
                        tri.presque_comb[tri.taille_b].c[j] = main.c[i+j];
                        main.c[i+j].use = true;
                    }
                    ++tri.taille_b;
                }
            }
        }
    }

    // Stocker les cartes non utilisées
    for(int i = 0; i < 15; ++i){
        if(main.c[i].use == false){
            tri.non_comb[index] = main.c[i];
            ++index;
        }
    }

    return tri;
}

bool gagne14(hand main, tri tri){
    if(tri.taille_b == 0){
        for(int i = 0; i < 14; ++i){
            if(main.c[i].use == false) return false;
        }
        return true;
    }
    return false;
}

bool gagne15(hand main, tri tri){
    if(tri.taille_b == 0){
        for(int i = 0; i < 15; ++i){
            if(main.c[i].use == false) return false;
        }
        return true;
    }
    return false;
}