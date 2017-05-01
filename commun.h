#ifndef DEF_COMMUN
#define DEF_COMMUN
#include <stdio.h>
#include <stdlib.h>





//#define TAILLE_MAX 5 // Pour le graphe 3
//#define TAILLE_MAX 6 // Pour les graphes 1, 4 et 5
#define TAILLE_MAX 7 // Pour le graphe 2


int nb_voisin_dominant_set; // pour la fonction liste_voisin_dominant_set


int calcul_nb_arc(int graphe[][TAILLE_MAX],int numero_noeud);
int* voisin(int graphe[][TAILLE_MAX],int numero_noeud);

#endif