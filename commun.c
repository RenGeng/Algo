
#include "commun.h"


//fonction qui calcule le nb d'arc (ie. le nb de voisin) d'un noeud
int calcul_nb_arc(int graphe[][TAILLE_MAX],int numero_noeud)
{
	if (numero_noeud == -1) return 0;
	int i;
	int res=0;
	for (i=0;i<TAILLE_MAX;i++)
	{
		res += graphe[numero_noeud][i];
	}

	return res;
}

//fonction qui renvoie un tableau contenant la la position des voisins
int* voisin(int graphe[][TAILLE_MAX],int numero_noeud)
{
	if (numero_noeud == -1) return 0;
	int i,j=0;
	int *tableau_voisin = (int*)malloc(calcul_nb_arc(graphe,numero_noeud)*sizeof(int));
	for (i = 0; i < TAILLE_MAX; i++)
	{
		if(graphe[numero_noeud][i]==1)
		{
			tableau_voisin[j++] = i;
		}
	}

	return tableau_voisin;
}


