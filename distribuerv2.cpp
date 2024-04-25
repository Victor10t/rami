/*void affiche_main(int nb_joueurs, hand * ens_main){
    for(int i = 0; i < nb_joueurs; ++i){
        std::cout << "\n Main n° " << i+1 << "\n";
        for(int j = 0; j < 14; ++j){
            std::cout << ens_main[i].c[j].valeur << " de " << ens_main[i].c[j].couleur << " | ";
        }
    }
}

hand * distribue_v3(int nb_joueurs, pioche & p){
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
}*/
