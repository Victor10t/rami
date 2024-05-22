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

void affiche_une_main(hand main){
    for(int i = 0; i < 14; ++i){
        std::cout << "(" << i << ") " << main.c[i].valeur << " " << main.c[i].couleur << " | ";
    }
}

void affiche_une_main_complete(tri tri, hand main){
    for(int i = 0; i < 15; ++i){
        std::cout << "(" << i << ") " << main.c[i].valeur << " " << main.c[i].couleur << " | ";
    }
    std::cout << "\n Tab combinaison :\n";
    for(int i = 0; i < tri.taille_a; ++i){
        for(int j = 0; j < 4; ++j){
            if(tri.comb_f[i].c[j].valeur != 0) std::cout << tri.comb_f[i].c[j].valeur << " " << tri.comb_f[i].c[j].couleur << " | ";
        }
    }
    std::cout << "\n Tab demi-combinaison :\n";
    for(int i = 0; i < tri.taille_b; ++i){
        for(int j = 0; j < 2; ++j){
            std::cout << tri.presque_comb[i].c[j].valeur << " " << tri.presque_comb[i].c[j].couleur << " | ";
        }
    }
    std::cout << "\n Carte non-utilisée :\n";
    for(int i = 0; i < 15; ++i){
        if(main.c[i].use == false){
            std::cout << main.c[i].valeur << " " << main.c[i].couleur << " | ";
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

/*bool check_brelan(tri tri){
    for(int i = 0; i < 5; i++){
        if(tri.non_comb[i].valeur == tri.non_comb[i+1].valeur && tri.non_comb[i].valeur == tri.non_comb[i+2].valeur) return true;
    }
    return false;
}*/

bool check_brelan(hand main){
    for(int i = 0; i < 14; ++i){
        int count = 1;
        for(int j = i+1; j < 15; ++j){
            if(main.c[i].use == false && main.c[j].use == false){
                if(main.c[i].valeur == main.c[j].valeur){
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


/*bool check_brelan(hand main)
{
    for(int i=0; i<14; ++i){
        for(int j=i+1; j<14; ++j){
            for(int k=j+1; k<14; ++k){
                if(main.c[i].valeur == main.c[j].valeur && main.c[i].valeur == main.c[k].valeur
                && main.c[i].couleur != main.c[j].couleur && main.c[i].couleur != main.c[k].couleur && main.c[j].couleur != main.c[k].couleur){
                return true;
                }
            }
        }
    }
    return false;
}*/

bool check_carre(hand main){
    for(int i = 0; i <= 11; ++i){
        int count = 1;
        for(int j = i+1; j <= 13; ++j){
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

bool check_suite(hand main){
    trier_main(main);
    int count = 1;
    for(int i = 0; i <= 11; ++i){
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

bool check_paire_suite(hand main){
    trier_main(main);
    int count = 1;
    for(int i = 0; i <= 12; ++i){
        if(main.c[i].valeur == main.c[i+1].valeur - 1 && main.c[i].couleur == main.c[i+1].couleur){
            count++;
            if(count >= 2){
                return true;
            }
        }else{
            count = 1;
        }
    }
    return false;
}

bool check_paire(hand main){
    int count = 1;
    for(int i = 0; i <= 13; ++i){
        for(int j = i+1; j <= 13; ++j){
            if(main.c[i].valeur == main.c[j].valeur){
                count++;
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
    tri.taille_a = 0; tri.taille_b = 0; int index = 0;
    /*while(check_carre(main) == true){
        trier_main(main);
        for(int i = 0; i < 11; ++i){
            if(main.c[i].valeur == main.c[i+1].valeur && main.c[i].valeur == main.c[i+2].valeur && main.c[i].valeur == main.c[i+2].valeur){
                for(int j = 0; j < 4; ++j){
                    tri.comb_f[tri.taille_a].c[j] = main.c[i+j];
                    main.c[i+j].use = true;
                }
                ++tri.taille_a;
            }
        }
    }*/
    while(check_brelan(main) == true){
        for(int i = 0; i < 11; ++i){
            if(main.c[i].use == false && main.c[i+1].use == false && main.c[i+2].use == false){
                if(main.c[i].valeur == main.c[i+1].valeur && main.c[i].valeur == main.c[i+2].valeur){
                    for(int j = 0; j < 3; ++j){
                        tri.comb_f[tri.taille_a].c[j] = main.c[i+j];
                        main.c[i+j].use = true;
                    }
                    ++tri.taille_a;
                }
            }
        }
    }/*
    while(check_suite(main) == true){
        trier_main(main); 
        for(int i = 0; i < 13; ++i){
            if(main.c[i].valeur == main.c[i+1].valeur - 1 && main.c[i].couleur == main.c[i+1].couleur){
                int count = 1;
                int j = i;
                while(main.c[j].valeur == main.c[j+1].valeur - 1 && main.c[j].couleur == main.c[j+1].couleur){
                    ++count;
                    ++j;
                }
                if(count >= 3){
                    for(int k = 0; k < count; ++k){
                        tri.comb_f[tri.taille_a].c[k] = main.c[i+k];
                        main.c[i+k].use = true;
                    }
                    tri.taille_a++;
                }
            }
        }
    }
    while(check_paire(main) == true){
        trier_main(main);
        for(int i = 0; i < 13; ++i){
            if(main.c[i].valeur == main.c[i+1].valeur){
                for(int j = 0; j < 2; ++j){
                    tri.presque_comb[tri.taille_b].c[j] = main.c[i+j];
                    main.c[i+j].use = true;
                }
                ++tri.taille_b;
            }
        }
    }
    while(check_paire_suite(main) == true){
        trier_main(main);
        for(int i = 0; i < 14; ++i){
            if(main.c[i].valeur == main.c[i+1].valeur - 1 && main.c[i].couleur == main.c[i+1].couleur){
                for(int j = 0; j < 2; ++j){
                    tri.presque_comb[tri.taille_b].c[j] = main.c[i+j];
                    main.c[i+j].use = true;
                }
                ++tri.taille_b;
            }
        }
        
    }
    int index = 0;
    for(int i = 0; i < 15; ++i){
        if(main.c[i].use == false){
            tri.non_comb[index] = main.c[i];
            ++index;
        }
    }
    std::cout << "Exiting organiser_main\n";*/
    for(int i = 0; i < 15; ++i){
        if(main.c[i].use == false){
            tri.non_comb[index] = main.c[i];
            ++index;
        }
    }
    return tri;
}
