#include <iostream>
#include "carte.h"
#include "pioche.h"
#include "main.h"

int main(){
    pioche p1;
    generer_jeu(p1);
    melange(p1);
    distribue(4, p1);
    return 0;
}