#include "algo_glouton.h"

//fonction pour savoir si une valeur est dans un tableau
int in_tableau_glouton(int val,int tab[],int taille_tableau)
{
	int i;
	for(i=0;i<taille_tableau;i++)
	{
		//if(tab[i] == -1) break;
		if (val == tab[i]) return 1;
	}
	return 0;
}

//fonction pour avoir le noeud qui a le plus de voisin dans la liste A
int max_voisin_glouton(int graphe[][TAILLE_MAX],int A[],int B[])
{
	int i,j,nb_voisin,nb_voisin_temp,noeud,nb_max = -1;
	int *liste_voisin;
	for(i=0;i<TAILLE_MAX;i++)
	{
		if (A[i] == -1) continue;
		nb_voisin = calcul_nb_arc(graphe,A[i]);
		nb_voisin_temp = nb_voisin;
		liste_voisin = voisin(graphe,A[i]);
		if(in_tableau_glouton(A[i],B,TAILLE_MAX)) nb_voisin++;
		for(j=0;j<nb_voisin_temp;j++)
		{
			if(!in_tableau_glouton(liste_voisin[j],B,TAILLE_MAX)) nb_voisin--;
		}
		if(nb_voisin>=nb_max)
		{
			nb_max = nb_voisin;
			noeud = i;
		}
	}
	return noeud;
}

//fonction qui calcule les voisins de chaque point du dominant_set
int* liste_voisin_dominant_set_glouton(int graphe[][TAILLE_MAX],int dominant_set[])
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
			if (in_tableau_glouton(liste_temp[j],liste_voisin,nb_voisin_dominant_set)) continue;
			//printf("Dans fonction liste_voisin_dominant_set_glouton\n");
			//printf("%d\n",liste_temp[j]);
			liste_voisin[k++] = liste_temp[j];
		}
	}

	return liste_voisin;
}

// Vérifie si un tableau est vide (ici on regarde si tous les valeurs du tableau valent -1 ou non)
int is_tableau_empty(int tableau[])
{
	int i;
	for(i=0;i<TAILLE_MAX;i++)
	{
		if(tableau[i]!=-1) return 0;
	}
	return 1;

}

int* algorithme_glouton(int graphe[][TAILLE_MAX])
{

	int i,noeud_max_voisin,k=0;
	int *liste_voisin_dominant;
	int *dominant_set = (int*)malloc(TAILLE_MAX*sizeof(int));
	int A[TAILLE_MAX],B[TAILLE_MAX];
	for (i = 0; i < TAILLE_MAX; i++) // pour initialiser le tableau à -1 et avoir un point avec un nb de voisin élévé
	{
		dominant_set[i] = -1;
		A[i] = i;
		B[i] = i;
	}

	do 
	{
		noeud_max_voisin = max_voisin_glouton(graphe,A,B);
		dominant_set[k++] = noeud_max_voisin;
		A[noeud_max_voisin] = -1; // Pour retirer
		B[noeud_max_voisin] = -1;
		liste_voisin_dominant=liste_voisin_dominant_set_glouton(graphe,dominant_set);
		for(i=0;i<nb_voisin_dominant_set;i++) B[liste_voisin_dominant[i]] = -1;
	} while(!is_tableau_empty(B));

	/*
	printf("%d\n",graphe[0][0]); // = 0
	printf("%d\n",graphe[0][3]); // = 1
	printf("%d\n",graphe[1][0]); // = 0
	printf("%d\n",graphe[4][4]); // = 0
	int a = calcul_nb_arc(graphe,0);
	printf("%d\n",a);
	printf("\n\n\n\n\n");
	int *b = voisin(graphe,0); 
	int *liste = voisin(graphe,1);

	printf("VOISIN de 4\n");
	printf("nb de voisin =%d\n",calcul_nb_arc(graphe,1));
	for (int i = 0; i < calcul_nb_arc(graphe,1); ++i)
	{
		printf("%d\n",liste[i]);
	}

*/	

	//free(liste_voisin_dominant);
	return dominant_set;
}


