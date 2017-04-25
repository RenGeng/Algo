#include<stdio.h>
#include<stdlib.h>

#define TAILLE_MAX 6
// Définition à la main du graphe
int graphe[TAILLE_MAX][TAILLE_MAX] = {

						{0,0,0,1,1,0},
						{0,0,0,1,0,1},
						{1,1,0,0,1,0},
						{1,1,1,0,1,0},
						{0,1,1,0,0,1},
						{0,1,1,0,1,0},
				   					 
				   					 };


//fonction qui calcule le nb d'arc (ie. le nb de voisin) d'un noeud
int calcul_nb_arc(int graphe[][TAILLE_MAX],int numero_noeud)
{
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
	int i,j=0;
	int *tableau_voinsin = (int*)malloc(calcul_nb_arc(graphe,numero_noeud)*sizeof(int));
	for (i = 0; i < TAILLE_MAX; i++)
	{
		if(graphe[numero_noeud][i]==1)
		{
			tableau_voinsin[j++] = i;
		}
	}

	return tableau_voinsin;
}

//fonction pour savoir si une valeur est dans un tableau
int in_tableau(int val,int tab[]) // Parcourir un tableau sans savoir sa taille..??
{
	int i;
	for(i=0;i<TAILLE_MAX;i++)
	{
		if (val == tab[i]) return 1;
	}
	return 0;
}

void main(void)
{

	int i,j,k=1;
	int dominant_set[TAILLE_MAX-1];
	for (i = 0; i < TAILLE_MAX; i++) // pour initialiser le tableau à -1 et avoir un point avec un nb de voisin élévé
	{
		dominant_set[i] = -1;
		if(calcul_nb_arc(graphe,i) >= 3)
			{
				dominant_set[0] = i;

			}
	}

	for(i=0;i<TAILLE_MAX;i++)
	{
		if(calcul_nb_arc(graphe,i) >= 3)
		{
			for(j=0;j<TAILLE_MAX;j++) //boucle pour regarder si le noeud qu'on considère est oui ou non un voisin des noeuds qu'on a déjà ajouté
			{
				if (!in_tableau(i,voisin(graphe,dominant_set[j])))
				{
					dominant_set[k++] = i;
				}
			}
		}
	}



	/*
	printf("%d\n",graphe[0][0]); // = 0
	printf("%d\n",graphe[0][3]); // = 1
	printf("%d\n",graphe[1][0]); // = 0
	printf("%d\n",graphe[4][4]); // = 0
	int a = calcul_nb_arc(graphe,0);
	printf("%d\n",a);
	printf("\n\n\n\n\n");
	int *b = voisin(graphe,0); 
	*/
	for (int i = 0; i < TAILLE_MAX; ++i)
	{
		printf("%d\n",dominant_set[i]);
	}

	
}