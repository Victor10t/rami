#include "carte.cpp"
#include "main.cpp"

struct maillon{
    carte c;
    maillon * suiv;
};
using pioche = maillon *;

/*pioche melange(pioche & p);
void distribue(pioche & p, main & m);
carte tirer(pioche & p, main & m);*/
