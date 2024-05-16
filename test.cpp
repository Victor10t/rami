#include <iostream>

struct carte{
    int valeur;
    std::string couleur;
    bool use;
};

struct hand{
    carte c[15];
};

struct tri{
    hand comb_f[5];
    hand presque_comb[7];
    carte non_comb[14];
    int taille_a;
    int taille_b;
};

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

bool check_suite(hand main){
    trier_main(main);
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

bool check_paire_suite(hand main){
    trier_main(main);
    int count = 1;
    for(int i = 0; i < 14; ++i){
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
    for(int i = 0; i < 13; ++i){
        for(int j = i+1; j < 14; ++j){
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

tri organiser_main(hand & main){
    tri tri;
    tri.taille_a = 0; tri.taille_b = 0;
    while(check_carre(main) == true){
        trier_main(main);
        for(int i = 0; i < 11; ++i){
            if(main.c[i].valeur == main.c[i+1].valeur && main.c[i].valeur == main.c[i+2].valeur && main.c[i].valeur == main.c[i+2].valeur){
                for(int j = 0; j < 4; ++j){
                    tri.comb_f[tri.taille_a].c[j] = main.c[i+j];
                    main.c[i].use = true;
                }
                ++tri.taille_a;
            }
        }
    }
    while(check_brelan(main) == true){
        trier_main(main);
        for(int i = 0; i < 12; ++i){
            if(main.c[i].valeur == main.c[i+1].valeur && main.c[i].valeur == main.c[i+2].valeur){
                for(int j = 0; j < 3; ++j){
                    tri.comb_f[tri.taille_a].c[j] = main.c[i+j];
                    main.c[i].use = true;
                }
                ++tri.taille_a;
            }
        }
    }
    while(check_suite(main) == true){
        trier_main(main);
        for(int i = 0; i < 14; ++i){
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
                        main.c[i].use = true;
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
                    main.c[i].use = true;
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
                    main.c[i].use = true;
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
    return tri;
}






