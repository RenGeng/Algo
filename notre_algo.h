#include "commun.h"

int in_tableau(int val,int tab[],int taille_tableau);
int max_voisin(int graphe[][TAILLE_MAX]);
int* notre_algo(int graphe[][TAILLE_MAX]);
int* liste_voisin_dominant_set(int graphe[][TAILLE_MAX],int dominant_set[]);