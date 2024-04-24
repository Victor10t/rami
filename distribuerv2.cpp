/*void distribue_v2(int nb_joueurs, pioche & p){
    hand * ens_main = new hand[nb_joueurs];
    for(int i = 0; i < nb_joueurs; ++i){
        int point_depart = 103 - 14*i;
        std::cout << "\n Main n° " << i+1 << "\n";
        for(int j = 0; j < 14; ++j){
            int a = rand() % (point_depart - j);
            ens_main[i].c[j] = p.c[a];
            carte z = p.c[a];
            p.c[a] = p.c[point_depart - j];
            p.c[point_depart - j] = z;
            std::cout << ens_main[i].c[j].valeur << " de " << ens_main[i].c[j].couleur << " | ";
        }
    }
}*/