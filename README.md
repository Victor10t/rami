# Projet C++ Rami

Ce projet est une implémentation du jeu de cartes Rami en C++.

## Comment utiliser

Pour utiliser ce programme, compilez tous les fichiers C++ dans le même dossier individuellement (ex pour main: `g++ -c main.cpp -o main.o`).Ensuite compilez tous les objets sur la même ligne pour obtenier une exécutable (`g++ main.o carte.o etc. -o exe.out`). Enfin, exécutez le fichier .out (`./exe.out`). Le programme se déroulera ensuite dans la console.

## Code

Le code est écrit en C++.
La Structure du projet est la suivante :
- `main.cpp` et `main.h`: Gestion de la main du joueur.
- `carte.cpp` et `carte.h`: Gestion des cartes du jeu.
- `defausse.cpp` et `defausse.h`: Gestion de la défausse.
- `pioche.cpp` et `pioche.h`: Gestion de la pioche.
- `jeu.cpp`: Logique principale du jeu.

## Limitations

Ce programme est une implémentation simple du Rami et ne comprend pas toutes les règles du jeu. Par exemple, il gère seulement le cas d'un rami sec.

## Améliorations futures

Des améliorations pourraient être apportées pour gérer plus de règles du jeu de Rami. De plus, une interface utilisateur pourrait être ajoutée pour rendre le jeu plus interactif.

