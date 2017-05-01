#include "commun.h"

int in_tableau_glouton(int val,int tab[],int taille_tableau);
int max_voisin_glouton(int graphe[][TAILLE_MAX],int A[],int B[]);
int is_tableau_empty(int tableau[]);
int* algorithme_glouton(int graphe[][TAILLE_MAX]);
int* liste_voisin_dominant_set_glouton(int graphe[][TAILLE_MAX],int dominant_set[]);