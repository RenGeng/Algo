#include "notre_algo.h"

//fonction pour savoir si une valeur est dans un tableau
int in_tableau(int val,int tab[],int taille_tableau)
{
	int i;
	for(i=0;i<taille_tableau;i++)
	{
		if(tab[i] == -1) break;
		if (val == tab[i]) return 1;
	}
	return 0;
}

//fonction pour avoir le noeud qui a le plus de voisin
int max_voisin(int graphe[][TAILLE_MAX])
{
	int i,nb_voisin,noeud,nb_max = -1;
	for(i=0;i<TAILLE_MAX;i++)
	{
		nb_voisin = calcul_nb_arc(graphe,i);
		if(nb_voisin>nb_max)
		{
			nb_max = nb_voisin;
			noeud = i;
		}
	}
	return noeud;
}

//fonction qui calcule les voisins de chaque point du dominant_set
int* liste_voisin_dominant_set(int graphe[][TAILLE_MAX],int dominant_set[])
{
	int i,j,k=0,nb_voisin_temp;
	nb_voisin_dominant_set = 0;
	for(i=0;i<TAILLE_MAX-1;i++)
	{
		if(dominant_set[i] == -1) break;
		nb_voisin_dominant_set+=calcul_nb_arc(graphe,dominant_set[i]);
	}
	int *liste_voisin = (int*)malloc(nb_voisin_dominant_set*sizeof(int)); // Pour stocker tous les voisins du dominant_set
	for(i=0;i<nb_voisin_dominant_set;i++) liste_voisin[i] = -1;

	int *liste_temp; // pour stocker les voisins d'un élément du dominant_set
	for(i=0;i<TAILLE_MAX-1;i++)
	{
		if(dominant_set[i] == -1) break; // Si c'est -1 alors tous ceux qui suit c'est aussi -1
		liste_temp = voisin(graphe,dominant_set[i]);
		nb_voisin_temp = calcul_nb_arc(graphe,dominant_set[i]);
		for(j=0;j<nb_voisin_temp;j++)
		{
			if (in_tableau(liste_temp[j],liste_voisin,nb_voisin_dominant_set)) continue;
			//printf("Dans fonction liste_voisin_dominant_set\n");
			//printf("%d\n",liste_temp[j]);
			liste_voisin[k++] = liste_temp[j];
		}
	}

	return liste_voisin;
}


int* notre_algo(int graphe[][TAILLE_MAX])
{

	int i,j,nb_voisin,cond_dedans = 1,noeud_max_voisin,k=1; //cond_dedans vaut 1 si aucun élément de liste_voisin est dans dominant_set, 0 sinon
	int *liste_voisin;
	int *liste_voisin_dominant;
	int *dominant_set = (int*)malloc(TAILLE_MAX*sizeof(int));
	for (i = 0; i < TAILLE_MAX; i++) // pour initialiser le tableau à -1 et avoir un point avec un nb de voisin élévé
	{
		dominant_set[i] = -1;
	}

	noeud_max_voisin = max_voisin(graphe);
	dominant_set[0] = noeud_max_voisin;
	liste_voisin_dominant=liste_voisin_dominant_set(graphe,dominant_set);

	for(i=0;i<TAILLE_MAX;i++)
	{
		if (in_tableau(i,dominant_set,TAILLE_MAX) || in_tableau(i,liste_voisin_dominant,TAILLE_MAX)) continue;
		liste_voisin = voisin(graphe,i);
		nb_voisin = calcul_nb_arc(graphe,i);
		for(j=0;j<nb_voisin;j++)
		{
			if(in_tableau(liste_voisin[j],liste_voisin_dominant,nb_voisin_dominant_set)==1) cond_dedans = 0; //il est dans la liste
		}
		if(cond_dedans)
		{
			dominant_set[k++] = i;
			free(liste_voisin_dominant);
			liste_voisin_dominant = liste_voisin_dominant_set(graphe,dominant_set);
		}
		cond_dedans = 1;
	}

	for(i=0;i<TAILLE_MAX;i++)
	{
		if (in_tableau(i,liste_voisin_dominant,nb_voisin_dominant_set) || in_tableau(i,dominant_set,TAILLE_MAX)) continue;
		dominant_set[k++] = i;
		free(liste_voisin_dominant);
		liste_voisin_dominant = liste_voisin_dominant_set(graphe,dominant_set);
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
	
	free(liste_voisin_dominant);
	return dominant_set;
}
